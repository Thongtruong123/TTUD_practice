#include <bits/stdc++.h>
using namespace std;

struct Route {
    vector<int> clients;
    int distance;
    int load;
};

struct Solution {
    vector<Route> routes;
    int totalDistance;
};

int n, K, Q, M;
vector<int> d;
vector<vector<int>> c;
vector<pair<int, int>> f;
int bestDistance = INT_MAX;
Solution bestSolution;

bool isValid(const Solution& sol) {
    // Kiểm tra xem mỗi khách hàng có được phục vụ đúng một lần
    vector<bool> visited(n + 1, false);
    for (const auto& route : sol.routes) {
        for (int client : route.clients) {
            if (visited[client]) return false;
            visited[client] = true;
        }
    }

    // Kiểm tra xem tổng tải trọng của mỗi xe không vượt quá Q
    for (const auto& route : sol.routes) {
        if (route.load > Q) return false;
    }

    // Kiểm tra xem các cặp khách hàng trong danh sách F không được phục vụ bởi cùng một xe
    for (const auto& [i, j] : f) {
        bool foundI = false, foundJ = false;
        for (const auto& route : sol.routes) {
            for (int client : route.clients) {
                if (client == i) foundI = true;
                if (client == j) foundJ = true;
            }
            if (foundI && foundJ) return false;
        }
    }

    return true;
}

int calculateTotalDistance(const Solution& sol) {
    int totalDistance = 0;
    for (const auto& route : sol.routes) {
        totalDistance += route.distance;
    }
    return totalDistance;
}

void backtrack(vector<int>& clients, int start, Solution& currentSolution) {
    if (start == n) {
        if (isValid(currentSolution)) {
            int totalDistance = calculateTotalDistance(currentSolution);
            if (totalDistance < bestDistance) {
                bestDistance = totalDistance;
                bestSolution = currentSolution;
            }
        }
        return;
    }

    for (int i = start; i < n; i++) {
        swap(clients[start], clients[i]);
        Route newRoute;
        newRoute.clients.push_back(clients[start] + 1);
        newRoute.distance = c[0][clients[start] + 1] + c[clients[start] + 1][0];
        newRoute.load = d[clients[start]];
        currentSolution.routes.push_back(newRoute);
        backtrack(clients, start + 1, currentSolution);
        currentSolution.routes.pop_back();
        swap(clients[start], clients[i]);
    }
}

int main() {
    cin >> n >> K >> Q;
    d.resize(n);
    c.resize(n + 1, vector<int>(n + 1));
    f.clear();

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        f.emplace_back(x, y);
    }

    vector<int> clients(n);
    iota(clients.begin(), clients.end(), 0);
    Solution currentSolution;
    backtrack(clients, 0, currentSolution);

    if (bestDistance == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << bestDistance << endl;
    }

    return 0;
}

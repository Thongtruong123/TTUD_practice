#include <bits/stdc++.h>

using namespace std;
int n1, n2;
int L, M, P;
vector<vector<int>> adj;
int cnt1 = 0, cnt2 = 0;
int ans = 0;
vector<int> check;
vector<vector<int>> solutions;
vector<int> current;

void Try(int i) {
    if (i > n1 + n2) {
        if (cnt1 >= 1 && cnt2 >= 1 && cnt1 + cnt2 <= L && cnt1 <= M && cnt2 <= M) {
            ans++;
            solutions.push_back(current);
        }
        return;
    }
    if (check[i] == 1) {
        Try(i + 1);
    } else {
        Try(i + 1);

        check[i] = 1;
        current.push_back(i);
        for(int u: adj[i]) check[u] = 1;
        if (i <= n1) {
            cnt1++;
        } else {
            cnt2++;
        }
        Try(i + 1);
        check[i] = 0;
        current.pop_back();
        for(int u: adj[i]) check[u] = 0;
        if (i <= n1) {
            cnt1--;
        } else {
            cnt2--;
        }
    }
}

int main() {
    cin >> n1 >> n2;
    cin >> L >> M >> P;
    adj.resize(n1 + n2 + 1);
    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    check.resize(n1 + n2 + 1, 0);
    Try(1);
    cout << ans << endl;
    for (const auto& sol : solutions) {
        for (int node : sol) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}





/*

THI CUỐI KỲ - THUẬT TOÁN ỨNG DỤNG HỌC KỲ 2023-2 (Kíp 3)
1
2
4
5
20%
20%
20%
30%
10%
Bố 1 (P1), ĐIỂM SỐ CUỘC THI
Con Người chơi ...n trong một cuộc thi. Điểm số của người chơi i là a[i] (i = l 2. Hãy tìm đếm số thấp nhất và cao nhất giữa n người chơi đó.
Vidy:
5
Dung là chưa tắc nguyên dương n (n = 100000)
Dùng 2 chứa n số nguyên dương a, a[2]. . ., a[n] (I < a[i] < 10000000)
Ghi ra điểm số thấp nhất và cao nhất giữa các người chơi (sau mỗi phần tử, có một ký tự SPACE)
24371
Dữ liệu vào (stdin)
Bải 1 (P1), CÓ PHIẾU
Kết quả (stdout)
17
M6 nhà đầu tư tài chính quyết định đầu tư vào 2 nhóm cổ phiếu, nhóm cổ phiếu ngành công nghệ và nhóm cổ phiếu ngành bán lẻ. Các mã cổ phiếu mà nhà đầu tư có thể lựa chọn đầu tư được đánh ĐỨC TIN 8 Mới Tin trong 10 các cổ phiếu ngành công nghệ có mã từ 1 tới ", và các cổ phiếu ngành bán lúc chị mà từ (n + 1) với (no + m2). Để giảm thiểu rủi ro tập trung, nhà đầu tư đưa ra chiến lược
như sau
(1) Không đầu tư quá L mã cổ phiếu khác nhau,
(2) Mỗi nhóm cổ phiếu, không đầu tư quá M mã cổ phiếu khác nhau,
(3) Mỗi nhóm cổ phiếu đầu tư ít nhất 1 mã cổ phiếu
(4) Mỗi nhóm cổ phiếu, đầu tư ít nhất một mã cổ phiếu,
Lập một danh sách gồm P cặp mã cổ phiếu không cùng đầu tư với nhau; mỗi cặp (“, và trong danh sách, nếu đầu tư vào mã cổ phiếu u thì sẽ không đầu tư và mã cổ phiếu vị ngược lại nếu đầu tư vào mã cổ phiếu y thi sẽ không đầu tư vào mã cổ phiếu u vi 2 mã cổ phiếu này có cúng chú sở hữu.
Ah một chiến lược, là một tập các mã có phiếu thỏa mãn các điều kiện trên, hỏi nhà đầu tư có bao
nhiều chiến lược đầu tư khác nhau.
• Dòng 1: gồm 2 số nguyên cách nhau bởi dấu cách, các giá trị này tương ứng với số lượng mà cổ phiếu trong mỗi nhóm (Hi, mà giá trị các số nguyên này nằm từ 1 tới 12;
 Dòng 2 : gồm 3 số nguyên L, M, P cách nhau bởi dấu cách.
 P dòng tiếp theo: mỗi dòng gồm 2 số nguyên dương cách nhau bởi dấu cách, là cặp mã cổ phiếu không đầu tư cùng nhau
 Tính số chiến lược thỏa mãn


MÀN KHI HÀNH VÀ CHI HỘI AN CUNG TÀI thiếu PHÁ tận chân phải chi ở nhà tại 2 này là nơi pha vy me them 2 ANH LÀ KHÔNG thứ nhất nối của 1 với ta chuối chi phi đi và tuồng thehar 2 vor samt chi phi 4)
TẠI KHÁCH KHI RA SỨC LÀ PHẢI VỊ VUA HẢI HỒ LỚN thông thái và tài ban quản lý đất nuớc ĐỘ KHI KHÁCH ĐÂM HƠN VÀ HÌNH KHI HÀNH HAI HANH NHẤT chúng, nhà vua đã đòi ra một bÀI HÀN de bila v hita hen phin thining on cho ai ed the giai quyet due
NHA KHOA KỲ ANH HAY RA NHÀ VÀ QUY ĐINH VỚI CHIỀU DÀI - VỊ THÀNH ĐÃ HAY thu cho thể từ loại HẢI HÀ HẬU LẠI HẠNG LH A Mi ca nhất của thu quốc. Mà đoạn của thành cỘ HỘ NHÀ HỘ MÀU MI ANH thành yêu chiều HÀI HÒA HỌ, VÀ HOÀ NHÀ THÁNH TÔI Cã hòa thu nhà bị thu được từ việc bán KHI HÀNH HÀN NHÀ THI CHU ĐỎ CHO ĐINH BỘ thần dân biết hàn PHÁ VỊ CỦA CÁc đoạn gỗ có chiều dan hot to Idén don vi là ph
NANH KHI HAI ANH LÀ PHÁP HAI CỦA HH Ca nhà cắt thành gỗ để có thể bản các đoàn đã cắt với tổng KHI ĐI KHI ANH. HÀN cho mình lài Hàng của mình và mình lấy phần thu
lớn từ nhà vua ĐÀNH HH TÍCH CHÍNH PHẢI CÓ HOA (SA: 1000 là chiều dài của thành n
NHƯ KHƯ KHƯ Anh 4 Huyndai 10h nhau bởi dấu cách là quá trị của các
Ả HAI HỘP SỐ NHva là giá trị lớn nhất có thể thu được bằng cách cắt thành gỗ ban đầu và KHI NÓ HÌNH ĐÃ BẮT
Vidus
22
18801017 17 20
8
24
3389 10 17 17 20
Gial thich
Các thành 1 đoạn độ dài 2 và Loại đồ dài 6
Các thành 8 đoàn độ dài 1
LAY: CÓ 10% SỐ (Ost the mun a520; 60% số test còn lại không có điều kiện gì thêm
BÀIS (105), NÉT NÓI TRUYỀN DỮ LIỆU
Một asing truyền thông đay biểu diễn bởi đồ thị vô hướng ở(1, 1) trong đó r = (1, 2
là tập cốc một, mình cạnh (, 1) có trong số "(I,V) (nếu cạnh (LP) được sử dụng để truyền dữ liệu thì ta cần hà một chi phi "(,")). Cho một nút phát tin x ( thuộc 1) và tập các nút nhận tin T(7 là tập con của 2), hay tìm tập con / các cạnh của ở để tạo thành một mạng truyền tin (tin được truyền từ 8 thông qua các cạnh của 77 đến các nút trong 7) với tổng chi phí (trong số các cạnh của tô) là nhỏ nhất
Dữ liệu vào:
• Dòng là chùa 2 số nguyên dường n, m (sas 500, 1m: 2000)
• DAI(1,2, m); chùa 8 số nguyên dương a, .w trong đó w là trọng số của cạnh
(v) (1s ws 200)
• Dòng 12: chứa nút phát s

3 3
3 3 6
2 3
1 5
4 1
2 5
3 1
5 4
10
*/

//
//  main.cpp
//  program12
//
//  Created by Macbook on 31/05/2024.
// Đêm Giao Thừa năm nay có n nhóm người tụ tập đứng dọc đường bờ hồ để xem pháo hoa. Các nhóm được đánh
//số từ 1 đến n theo thứ tự từ đầu đường đến cuối đường, nhóm thứ i có ai người.
//Sắp đến giờ xem pháo hoa, các nhóm này sẽ hợp nhất với nhau để tạo thành một nhóm duy nhất. Quá trình hợp
//nhất nhóm diễn ra như sau:
//• Nếu chỉ còn một nhóm thì dừng quá trình.
//• Ngược lại, hai nhóm kề nhau sẽ hợp lại với nhau: Nhóm 1 hợp lại với nhóm 2, nhóm 3 hợp lại với nhóm 4,
//... Nếu có lẻ nhóm, nhóm sau cùng sẽ không phải làm gì.
//• Đánh số lại các nhóm mới từ đầu đường đến cuối đường, bắt đầu từ 1.
//• Lặp lại bước một.
//Thời gian cần để hai nhóm hợp nhất với nhau bằng tổng số người trong hai nhóm. Mỗi lần hợp nhất, các nhóm sẽ
//thực hiện song song, sau đó chờ các nhóm khác thực hiện xong để tiếp tục lần hợp mới. Do đó thời gian cần cho
//mỗi lần hợp nhất (tức mỗi vòng lặp) sẽ là lượng thời gian lớn nhất trong số các cặp nhóm cần hợp. Cụ thể, thời
//gian mà k nhóm b1, b2, . . . , bk cần để thực hiện một lần hợp nhất là max(b1 + b2, b3 + b4, . . . , bk−1 + bk) nếu k chẵn,
//và max(b1 + b2, b3 + b4, . . . , bk−2 + bk−1) nếu k lẻ.
//Yêu cầu: Hãy tính tổng thời gian hợp nhất của tất cả các nhóm người.

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n;
int a[maxT];
int b[maxT];
int timeT=0;


int caculate(int k){
    int maxx=0;
    for (int i=0;i<=k/2;i++) if (maxx<a[i]) maxx=a[i];
    return maxx;
}

void myFuntion(int k){
    if (k!=1){
        if (k%2==0){
            for (int i=1;i<=k/2;i++) a[i]=a[2*i-1]+a[2*i];
            timeT+=caculate(k);
            myFuntion(k/2);
        }
        else{
            for (int i=1;i<=k/2;i++) a[i]=a[2*i-1]+a[2*i];
            a[k/2+1]=a[k];
            timeT+=caculate(k);
            myFuntion(k/2+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    myFuntion(n);
    cout<<timeT;
    return 0;
}

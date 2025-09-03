#include <bits/stdc++.h>
using namespace std;

// int func(int pts[][2], int n){
//     int ct=0;
//     for(int i=0; i<n; i++){
//         int x1 = pts[i][0];
//         int y1 = pts[i][1];
//         for(int j=0; j<n; j++){
//             if(i==j)    continue;
//             int x2 = pts[j][0];
//             int y2 = pts[j][1];
//             if(x1<=x2 && y1>=y2){
//                 bool hasPointInside= false;
//                 for(int k=0; k<n; k++){
//                     if(k==i || k==j)
//                         continue;
//                     int x3= pts[k][0];
//                     int y3= pts[k][1];
//                     if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
//                         hasPointInside= true;
//                         break;
//                     } 
//                 }
//                 if(!hasPointInside) ct++;
//             }
//         }
//     }
//     return ct;
// }


int func2(vector<vector<int>> &pts, int n){
    int ct=0;

    auto lambda= [](vector<int> &point1, vector<int> &point2){
        if(point1[0]== point2[0]){
            return point1[1]>point2[1];
        }
        return point1[0]<point2[0];
    };

    sort(begin(pts), end(pts), lambda);
    for(int i=0; i<n; i++){
        int x1 = pts[i][0];
        int y1 = pts[i][1];

        int maxY= INT_MIN;
        for(int j=i+1; j<n; j++){
            int x2 = pts[j][0];
            int y2 = pts[j][1];
            if(y2>y1){
                continue;
            }
            if(y2>maxY){
                ct++;
                maxY=y2;
            }
        }
    }
    return ct;
}

int main(){
    cout<<"Enter number of points: ";
    int n;
    cin>>n;
    vector<vector<int>> pts(n, vector<int>(2)); 
    cout<<"Enter points: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            if(j%2==0)  cout<<"Enter X value for point "<<i+1<<" : ";
            else    cout<<"Enter Y value for point "<<i+1<<" : ";
            cin>>pts[i][j];
        }
    }
    cout<<"Output: "<<func2(pts, n);
}
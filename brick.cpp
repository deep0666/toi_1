#include<iostream>
using namespace std;

int main(){

    int n, m, a;
    cin >> n >> m;

    //���ҧ���ҧ ����Ѻ���
    char data[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> data[i][j];
        }
    }

    //�����礵��ҧ
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << data[i][j];
//        }
//        cout << endl;
//    }

    //�Ѻ��� a �ӹǹ m ����
    for(int i=0; i<m; i++){
        cin >> a;

        for(int j=0; j<a; j++){
            //������ y_check = -1 �繨ش�������
            int y_check = -1;

            //����� y_check ����� 'O' ����  '#'  ���
            //����������� y_check-1 = '.' ��� y_check = '#'
            do{
                data[y_check-1][i] = '.';
                data[y_check][i] = '#';
                y_check++;
            }while(data[y_check][i] != 'O' && data[y_check][i] != '#' && y_check != n);
        }
    }

    //�ʴ����������͡
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << data[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
8 5
.....
.....
.OO..
.....
.O...
...O.
.....
.....
1 1 3 2 0
*/

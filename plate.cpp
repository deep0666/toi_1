#include<iostream>
using namespace std;

int main(){

    bool exit = false;
    int nc, ns;
    cin >> nc >> ns;

    int c[ns], s[ns];
    for(int i=0; i<ns; i++){
        cin >> c[i] >> s[i];
    }

    //��˹���Ҥ�� �Ѻ��� id ����͡�ҡ�� ��Шӹǹ����͡����
    int q[ns][2], countQ = -1, temp[ns], countTemp = 0;

    //exit = true ��ԡ�ӧҹ
    while(exit == false){
        //�Ѻ�����
        char command[2];
        cin >> command;

        if(command[0] == 'E'){
            //�Ѻ id
            int id, room;
            cin >> id;

            //����� id ��������ͧ�˹
            for(int i=0; i<ns; i++){
                if(id == s[i]) room = c[i];
            }

            //�ҡ�ѧ������õ�ͤ������������
            if(countQ == -1){
                q[countQ+1][0] = room;
                q[countQ+1][1] = id;
            }
            else{
                //�����������ͧ���ǡѹ���
                for(int i=countQ; i>=0; i--){

                    //���������ͧ���ǡѹ ������¤���������͹�͡� �����á����ͧ
                    if(q[i][0] == room){
                        for(int j=countQ; j>i; j--){
                            q[j+1][0] = q[j][0];
                            q[j+1][1] = q[j][1];
                        }
                        q[i+1][0] = room;
                        q[i+1][1] = id;

                        break;
                    }
                    //����������������ͧ���ǡѹ 仵����ѧ��
                    else if(q[i][0] != room && i == 0){
                        q[countQ+1][0] = room;
                        q[countQ+1][1] = id;
                    }
                }
            }

            countQ++;
        }
        else if(command[0] == 'D'){

            //�纤�Ҥ�����͡�ҡ��
            temp[countTemp] = q[0][1];
            countTemp++;

            //��餹���仢����
            for(int i=0; i<countQ; i++){
                q[i][0] = q[i+1][0];
                q[i][1] = q[i+1][1];
            }

            countQ--;
        }
        else if(command[0] == 'X'){
            exit = true;
        }
    }

    for(int i=0; i<countTemp; i++){
        cout << temp[i] << endl;
    }
    cout << "0";

    return 0;
}
/*
2 6
1 41
1 42
1 43
2 201
2 202
2 203
E 41
E 201
D
E 202
E 42
E 43
D
E 203
D
D
D
X
*/

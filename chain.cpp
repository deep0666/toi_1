#include<iostream>
#include<string.h>
using namespace std;

int main(){

    int l, n;
    bool chain = false;
    cin >> l >> n;

    //���ҧ text[l+1], text_temp[l+1] (���������º��º)
    char text[l+1], text_temp[l+1];

    for(int i=0; i<n; i++){
        cin >> text;

        //�ҡ i = 0 ����ͻ text ���� text_temp
        if(i == 0) strcpy(text_temp, text);
        //�ҡ chain = false ��������ѧ���Ҵ
        else if(chain == false){
            int like = 0;

            //���º��º����ѡ������͹�ѹ���
            for(int j=0; j<l; j++){
                if(text[j] == text_temp[j]) like++;
            }

            //�ҡ�ѡ�ù�͡��� l-2 �����ӢҴ chain = true
            if(like < l-2) chain = true;
            //�ҡ�������� text ���� text_temp
            else strcpy(text_temp, text);
        }
    }

    cout << text_temp;

    return 0;
}
/*
4
12
HEAD
HEAP
LEAP
TEAR
REAR
BAER
BAET
BEEP
JEEP
JOIP
JEIP
AEIO
*/

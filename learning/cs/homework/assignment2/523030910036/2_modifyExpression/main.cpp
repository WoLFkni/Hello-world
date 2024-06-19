#include <iostream>

using namespace std;
/*
������������ڶ�Ӧλ��ʱ�Ľ��
���룺ԭʼ�ַ�����string����ǰ����λ�ã�int����������λ�ã�int�����Ӻ�λ�ã�int��
�������������int��
ȫ��״̬�����ı�
*/
int addparenthesis(string origin, int posbefore, int posafter, int pos){
    int before = 0, addition = 0, after = 0;
    if (posbefore == 0){
        before = 1;
    }else{
        before = stoi(origin.substr(0,posbefore));
    }
    addition = stoi(origin.substr(posbefore,pos-posbefore)) + stoi(origin.substr(pos+1,posafter-pos));
    if (posafter == (origin.length()-1)){
        after = 1;
    }else{
        after = stoi(origin.substr(posafter+1,origin.length()-posafter));
    }
    return before*addition*after;
}
/*
�޸ı��ʽ�õ�����ֵ
*/
int main()
{
    string origin = "";
    int tgt = 0;
    cin >> origin >> tgt;
    size_t n = origin.find("+");
    int approach = 0, order1 = 0, order2 = origin.length()-1;
    approach = addparenthesis(origin, order1, order2, n);
    for (int i = n-1; i>=0; i--){
        for (int j = n+1; j<=origin.length()-1; j++){
            int dis = addparenthesis(origin, i, j, n);
            if (abs(dis-tgt)<abs(approach-tgt)){
                approach = dis;
                order1 = i;
                order2 = j;
            }
        }
    }
    origin.insert(order1,"(");
    origin.insert(order2+2,")");
    cout << origin << endl;
    return 0;
}

#include <iostream>

using namespace std;
/*
�ж��Ƿ�����
���룺���
�����0���������꣩/1�������꣩
ȫ��״̬�����ı�
*/
bool isleapyear(int year){
    if (year % 4 != 0){
        return false;
    }
    if (year % 100 != 0){
        return true;
    }
    if (year % 400 == 0){
        return true;
    }
    return false;
}
/*
����������ַ����õ���ݣ�Int��
���룺�ַ�������/��/�գ�
������꣨int��
ȫ��״̬�����ı�
*/
int getyear(string date){
    date = date.substr(0,4);
    return stoi(date);
}
/*
����������ַ����õ��·ݣ�Int��
���룺�ַ�������/��/�գ�
������£�int��
ȫ��״̬�����ı�
*/
int getmonth(string date){
    date = date.substr(5,2);
    return stoi(date);
}
/*
����������ַ����õ����ڣ�Int��
���룺�ַ�������/��/�գ�
������գ�int��
ȫ��״̬�����ı�
*/
int getday(string date){
    date = date.substr(8,2);
    return stoi(date);
}
/*
������������֮����������������Щ���������
���룺��ʼ�꣨int���������꣨int���������int��
�������
ȫ�ֱ��������������м�����ݵ��µ�������
*/
void yeardis(int y1, int y2, int& dis){
    for (int i = y1+1; i<=y2-1; i++){
        if (isleapyear(i)){
            dis += 366;
        }else{
            dis += 365;
        }
    }
}
/*
��ʼ������֮���������·�ʣ�µ�������3����12�£�
���룺�·ݣ�int��
�����ʣ�µ�������int��
ȫ��״̬�����ı�
*/
int behind(int month){
    switch (month){
    case 3:
       return 6*31+4*30;
    case 4:
        return 5*31+4*30;
    case 5:
        return 5*31+3*30;
    case 6:
        return 4*31+3*30;
    case 7:
        return 4*31+2*30;
    case 8:
        return 3*31+2*30;
    case 9:
        return 2*31+2*30;
    case 10:
        return 2*31+30;
    case 11:
        return 31+30;
    case 12:
        return 31;
    }
    return 0;
}
/*
������ʣ�µ�����(��������)
���룺�·ݣ�int�������ڣ�int��
�����ʣ�µ�������int��
ȫ��״̬�����ı�
*/
int monthremain(int month, int day){
    switch (month){
    case 1:
        return 31 - day +1;
    case 3:
        return 31 - day +1;
    case 4:
        return 30 - day +1;
    case 5:
        return 31 - day +1;
    case 6:
        return 30 - day +1;
    case 7:
        return 31 - day +1;
    case 8:
        return 31 - day +1;
    case 9:
        return 30 - day +1;
    case 10:
        return 31 - day +1;
    case 11:
        return 30 - day +1;
    case 12:
        return 31 - day +1;
    }
    return 0;
}
/*
����������ǰ������������2�£�
���룺�£�int�����գ�int��
�����������int��
ȫ��״̬�����ı�
*/
int gapfeb(int month, int day){
    switch (month){
    case 1:
        return day;
    case 2:
        return 31+day;
    case 3:
        return 31+day;
    case 4:
        return 31*2+day;
    case 5:
        return 31*2+30+day;
    case 6:
        return 31*3+30+day;
    case 7:
        return 31*3+30*2+day;
    case 8:
        return 31*4+30*2+day;
    case 9:
        return 31*5+30*2+day;
    case 10:
        return 31*5+30*3+day;
    case 11:
        return 31*6+30*3+day;
    case 12:
        return 31*6+30*4+day;
    }
    return 0;
}
/*
��ʼ��ͽ���������������֮���֮ǰ������
���룺��ʼ�£������£���ʼ���ڣ��������ڣ�int������ʼ���Ƿ����꣬�������Ƿ�����(bool)����������int��
�������
ȫ��״̬�����������������ʼ������֮��ģ��ͽ���������֮ǰ��
*/
void m_d_dis(int m1, int m2, int d1, int d2, bool l1, bool l2, int& dis){
    if (m1 > 2 && m1 < 12){
        dis += behind(m1 + 1);
        dis += monthremain(m1, d1);
    }
    else if(m1 == 12){
        dis += monthremain(12, d1);
    }
    else if (m1 == 1){
        dis += monthremain(1, d1)+ behind(3);
        if (l1){
            dis += 29;
        }else{
            dis += 28;
        }
    }
    else{
        dis += behind(3);
        if (l1){
            dis += 29 - d1 +1;
        }else{
            dis += 28 -d1 +1;
        }
    }

    if (m2 > 2){
        if (l2){
            dis += gapfeb(m2,d2)+29;
        }else{
            dis += gapfeb(m2,d2)+28;
        }
    }
    else {
        dis += gapfeb(m2,d2);
    }
}
/*
������������֮���ʱ�����
*/
int main()
{
    string date1 = "",date2 = "";
    cin >> date1 >> date2;
    int y1,y2,m1,m2,d1,d2, dis = 0;
    y1 = getyear(date1);
    y2 = getyear(date2);
    m1 = getmonth(date1);
    m2 = getmonth(date2);
    d1 = getday(date1);
    d2 = getday(date2);
    if (y1 < y2){
        yeardis(y1,y2, dis);
        m_d_dis(m1,m2,d1,d2,isleapyear(y1),isleapyear(y2),dis);
    }
    else if(y1 > y2){
        dis = 0;
    }
    else{
        if(m1 > m2){
            dis = 0;
        }
        else if (m1 == m2){
            if (d1 > d2){
                dis = 0;
            }else{
                dis = d2 - d1 + 1;
            }
        }
        else{
            m_d_dis(m1,m2,d1,d2,isleapyear(y1),isleapyear(y2),dis);
            dis -= 366*(isleapyear(y1))+365*(!(isleapyear(y1)));
        }
    }
    cout << dis-1 <<endl;
    return 0;
}

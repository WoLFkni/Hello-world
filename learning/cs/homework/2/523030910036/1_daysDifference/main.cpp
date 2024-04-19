#include <iostream>

using namespace std;
/*
判断是否闰年
输入：年份
输出：0（不是闰年）/1（是闰年）
全局状态：不改变
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
根据输入的字符串得到年份（Int）
输入：字符串（年/月/日）
输出：年（int）
全局状态：不改变
*/
int getyear(string date){
    date = date.substr(0,4);
    return stoi(date);
}
/*
根据输入的字符串得到月份（Int）
输入：字符串（年/月/日）
输出：月（int）
全局状态：不改变
*/
int getmonth(string date){
    date = date.substr(5,2);
    return stoi(date);
}
/*
根据输入的字符串得到日期（Int）
输入：字符串（年/月/日）
输出：日（int）
全局状态：不改变
*/
int getday(string date){
    date = date.substr(8,2);
    return stoi(date);
}
/*
根据两个日期之间完整的年份求出这些年的天数差
输入：开始年（int），结束年（int），天数差（int）
输出：无
全局变量：在天数差中加上年份导致的天数差
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
开始年日期之后完整的月份剩下的天数（3月至12月）
输入：月份（int）
输出：剩下的天数（int）
全局状态：不改变
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
所在月剩下的天数(不含二月)
输入：月份（int），日期（int）
输出：剩下的天数（int）
全局状态：不改变
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
结束年日期前的天数（跳过2月）
输入：月（int），日（int）
输出：天数（int）
全局状态：不改变
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
起始年和结束年两年里日期之后和之前的天数
输入：起始月，结束月，起始日期，结束日期（int），起始年是否闰年，结束年是否闰年(bool)，总天数（int）
输出：无
全局状态：在总天数里加上起始年日期之后的，和结束年日期之前的
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
计算两个日期之间的时间距离
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

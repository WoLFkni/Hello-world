#include <iostream>
#include <iomanip>

using namespace std;
/*
该程序实现根据交大的计算规则，根据课程的成绩和学分，计算平均积点GPA。
输入一个数n，代表门数。
接下来依次输入课程的考试成绩和学分，中间通过空格隔开。
输出是一个double类型的小数。
*/
int main()
{
    double totalGPA = 0.0;
    int n;
    cin >> n;
    double TotalCredit = 0, TotalGPA = 0;
    for (int i = 1; i <= n; i++){
        double score, credit;
        cin >> score >> credit;
        TotalCredit += credit;
        if (score >= 70){
            switch(int (score / 5)){
            case 20:
                TotalGPA += 4.3*credit;
                break;
            case 19:
                TotalGPA += 4.3*credit;
                break;
            case 18:
                TotalGPA += 4.0*credit;
                break;
            case 17:
                TotalGPA += 3.7*credit;
                break;
            case 16:
                TotalGPA += 3.3*credit;
                break;
            case 15:
                TotalGPA += 3.0*credit;
                break;
            case 14:
                TotalGPA += 2.7*credit;
                break;
            }
        }else{
            if (score >= 67){
                TotalGPA += 2.3*credit;
            }else{
                if (score >= 65){
                    TotalGPA += 2.0*credit;
                }else{
                    if (score >= 62){
                        TotalGPA += 1.7*credit;
                    }else{
                            TotalGPA +=1.0*credit;
                    }
                }
            }
        }
    }
    totalGPA = TotalGPA/TotalCredit;
    cout << fixed << setprecision(6) << totalGPA << endl;
    return 0;
}

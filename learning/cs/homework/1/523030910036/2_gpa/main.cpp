#include <iostream>
#include <iomanip>

using namespace std;
/*
�ó���ʵ�ָ��ݽ���ļ�����򣬸��ݿγ̵ĳɼ���ѧ�֣�����ƽ������GPA��
����һ����n������������
��������������γ̵Ŀ��Գɼ���ѧ�֣��м�ͨ���ո������
�����һ��double���͵�С����
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

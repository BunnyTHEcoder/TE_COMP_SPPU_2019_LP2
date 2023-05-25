#include <iostream>
#include <string>
using namespace std;

int main()
{
    string m1, m2, m3, e1, e2, e3;
    
    cout << "--------Manager------" << endl;
    cout << "Did the employee meet their assigned goals and objectives? (yes/no): ";
    cin >> m1;

    cout << "Have they acquired new skills or knowledge relevant to their role? (yes/no): ";
    cin >> m2;

    cout << "How well do they contribute to a positive team dynamic and support their colleagues? (bad/good/very good): ";
    cin >> m3;

    cout << "-----------Employee-----------" << endl;
    cout << "Did you consistently meet project or task deadlines? (yes/no): ";
    cin >> e1;

    cout << "Did you maintain a positive and professional attitude in the workplace? (yes/no): ";
    cin >> e2;

    cout << "Did you show adaptability in handling changes or new assignments? (yes/no): ";
    cin >> e3;

    // Assessing the overall employee performance
    cout << "--------Performance Evaluation--------" << endl;
    cout << "Based on the evaluation:" << endl;

    if (m1 == "yes" && m2 == "yes" && m3 == "very good" && e1 == "yes" && e2 == "yes" && e3 == "yes") {
        cout << "The employee's performance is excellent." << endl;
    }
    else if ((m1 == "yes" && m2 == "yes" && e1 == "yes") || (m1 == "yes" && m3 == "good" && e1 == "yes" && e2 == "yes") || (m1 == "yes" && m2 == "yes" && e2 == "yes" && e3 == "yes")) {
        cout << "The employee's performance is good." << endl;
    }
    else {
        cout << "The employee's performance needs improvement." << endl;
    }

    return 0;
}

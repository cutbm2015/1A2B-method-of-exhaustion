// _1A2B.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int> possiblePool;
bool validNum(int ip) {
    vector<int> target;
    for (int i = 3; i >= 0; i--) {
        target.push_back(ip / pow(10, i));
        ip -= target.at(3 - i) * pow(10, i);
    }
    /*for (auto x : target)
       cout << x << ",";
    cout << endl;*/
    for (int j = 0; j <= 9; j++) {
        if (count(target.begin(), target.end(), j) >= 2) {
            return false;
        }
    }
    

    return true;
}
void possiblePoolInit() {
    for (int i = 0; i <= 9999; i++) {
        if(validNum(i))
            possiblePool.push_back((i));        
    }
    /*for (auto p : possiblePool) {
        cout << p << ",";
    }*/
}

void deleteNum(int i) {
    //從pool中刪除i
    vector<int>::iterator f = find(possiblePool.begin(), possiblePool.end(), i);
    if (f != possiblePool.end()) {
        possiblePool.erase(f);
    }
}
void deleteNumContent(int target) {
    vector<int> v_pool;
    vector<int> v_del;
    for (int i = 3; i >= 0; i--) {
        v_del.push_back(target / pow(10, i));
        target -= v_del.at(3 - i) * pow(10, i);
    }

    int temp;
    for (auto p : possiblePool) {
        temp = p;
        v_pool.clear();
        for (int i = 3; i >= 0; i--) {
            v_pool.push_back(temp / pow(10, i));
            temp -= v_pool.at(3 - i) * pow(10, i);
        }
        for (int j = 0; j < 4; j++) {
            if (count(v_pool.begin(), v_pool.end(), v_del.at(j)) > 0) {
                deleteNum(p);
                cout << "del" << p << " succ";
            }
        }
    }


}
int verifyA(int ans, int gue) {
    //how many A
    vector<int> v_ans;
    vector<int> v_gue;
    for (int i = 3; i >= 0; i--) {
        v_ans.push_back(ans / pow(10, i));
        ans -= v_ans.at(3 - i) * pow(10, i);

        v_gue.push_back(gue / pow(10, i));
        gue -= v_gue.at(3 - i) * pow(10, i);
    }
    /*for (auto x : v_gue)
        cout << x << ",";
    cout << endl;*/
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        if (v_ans.at(i) == v_gue.at(i))
            counter++;
    }
    return counter;

}
//5 9 7 6
//1 9 6 2
int verifyB(int ans, int gue) {
    //how many A
    vector<int> v_ans;
    vector<int> v_gue;
    for (int i = 3; i >= 0; i--) {
        v_ans.push_back(ans / pow(10, i));
        ans -= v_ans.at(3 - i) * pow(10, i);

        v_gue.push_back(gue / pow(10, i));
        gue -= v_gue.at(3 - i) * pow(10, i);
    }
    
    for (int i = 0; i < 4; i++) {
        if (v_ans.at(i) == v_gue.at(i))
        {
            v_ans[i] = -1;
            v_gue[i] = -1;
        }
    }

    sort(v_ans.begin(), v_ans.end());
    sort(v_gue.begin(), v_gue.end());

    vector<int>::iterator repeator;
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        //cout << v_ans[0] << v_ans[1] << v_ans[2] << v_ans[3] << "中找" << v_gue[i];
        repeator = find(v_ans.begin(), v_ans.end(), v_gue[i]);
        if (repeator != v_ans.end() && (v_ans.at(i) != -1)) {
            //表找到
            counter++;
        }
    }
    return counter;
    //1 9 6 2
    //6 9 7 3
    //1 -1 6 2
    //6 -1 7 3
}
void exhaustion(int gue, int A, int B) {
    if (A == 0 && B == 0) {
        deleteNumContent(gue);
    }
    for (int i = 0; i <= 9999; i++) {
        if (verifyA(i, gue) != A ) {
            //do_delete
            deleteNum(i);
            //cout << "del " << i << " succ";
        }
    }
}
int main()
{
    possiblePoolInit();
    int answer = 5649;
    int guess, gueA = 0, gueB = 0;
    cout << "1A2B 窮舉器" << endl << "答案(輸入0表未知): ";
    cin >> answer;
    while (true) {

       
        cout << "猜測值: ";
        cin >> guess;

        if (answer == 0) {
            cout << "A值: ";
            cin >> gueA;
            cout << "B值: ";
            cin >> gueB;
        }
        else {
            if (guess == answer) {
                cout << "correct!" << endl;
                return 0;
            }
            gueA = verifyA(answer, guess);
            gueB = verifyB(answer, guess);
        }
        
        system("cls");

        //cout << "答案 " << answer << "猜測 " << guess << endl;
        exhaustion(guess, gueA, gueB);

        cout << "可能值: ";
        for (auto p : possiblePool) {
            if (p < 1000) {
                cout << "0";
            }
            cout << p << ",";
        }
        cout << endl;
        //cout << verifyA(answer, guess) << "A" << endl;
        //cout << verifyB(answer, guess) << "B";
    }
        return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

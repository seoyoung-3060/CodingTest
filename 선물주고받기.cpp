#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, map<string, int> > giftExchange;
    map<string, int> giftScore;
    map<string, int> findMax;
    
    for(auto const& name : friends) {
        giftScore[name] = 0;
        findMax[name] = 0;
        for(auto const& name2 : friends) {
            giftExchange[name][name2] = 0;
        }
    }
    
    for(auto const& gift : gifts) {
        stringstream ss(gift);
        string give, take;
        ss >> give >> take;
        giftExchange[give][take]++;
        giftScore[give]++;
    }
    
    for(int i=0; i<friends.size(); i++) {
        string name = friends[i];
        for(int j=i+1; j<friends.size(); j++) {
            string name2 = friends[j];
            if(name != name2) {
                int one = giftExchange[name][name2];
                int two = giftExchange[name2][name];
                
                if(one > two) findMax[name]++;
                else if(one < two) findMax[name2]++;
                else {
                    if(giftScore[name] > giftScore[name2]) findMax[name]++;
                    else{
                        if(giftScore[name] < giftScore[name2]) findMax[name2]++;
                    }
                }
            }
        }
    }

    for(auto x : findMax) {
        cout << x.second << endl;
        answer = max(answer, x.second);
    }
    
    return answer;
}

int main(void) {
    vector<string> friends1;
    friends1.push_back("muzi");
    friends1.push_back("ryan");
    friends1.push_back("frodo");
    friends1.push_back("neo");

    vector<string> gifts1;
    gifts1.push_back("muzi frodo");
    gifts1.push_back("muzi frodo");
    gifts1.push_back("ryan muzi");
    gifts1.push_back("ryan muzi");
    gifts1.push_back("ryan muzi");
    gifts1.push_back("frodo muzi");
    gifts1.push_back("frodo ryan");
    gifts1.push_back("neo muzi");

    vector<string> friends2;
    friends2.push_back("joy");
    friends2.push_back("brad");
    friends2.push_back("alessandro");
    friends2.push_back("conan");
    friends2.push_back("david");

    vector<string> gifts2;
    gifts2.push_back("alessandro brad");
    gifts2.push_back("alessandro joy");
    gifts2.push_back("alessandro conan");
    gifts2.push_back("david alessandro");
    gifts2.push_back("alessandro david");

    vector<string> friends3;
    friends3.push_back("a");
    friends3.push_back("b");
    friends3.push_back("c");

    vector<string> gifts3;
    gifts3.push_back("a b");
    gifts3.push_back("b a");
    gifts3.push_back("c a");
    gifts3.push_back("a c");
    gifts3.push_back("a c");
    gifts3.push_back("c a");

    solution(friends1, gifts1);

    return 0;
}
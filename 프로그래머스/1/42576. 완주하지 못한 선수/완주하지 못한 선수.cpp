#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> participant_map;
    
    // 1) 참가자 이름 출현 횟수 세기
    for(const auto& name : participant) {
        participant_map[name]++;
    }
    
    // 2) 완주자 이름 출현 횟수 감소
    for(const auto& name : completion) {
        participant_map[name]--;
    }
    
    // 3) 미완주자 이름 찾기
    for(const auto& entry : participant_map) {
        if (entry.second > 0) {
            return entry.first;
        }
    }
    
    // 4) 전원 완주
    return "";
    
    
}
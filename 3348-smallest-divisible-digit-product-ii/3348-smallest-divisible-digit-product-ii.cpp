#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int,int>> kFactorCounts = {
        {0, {}}, {1, {}}, {2, {{2,1}}}, {3, {{3,1}}}, {4, {{2,2}}},
        {5, {{5,1}}}, {6, {{2,1},{3,1}}}, {7, {{7,1}}}, {8, {{2,3}}}, {9, {{3,2}}}
    };

    unordered_map<int,int> subtract(unordered_map<int,int> a, const unordered_map<int,int>& b) {
        for (auto& [k, v] : b) a[k] = max(0, a[k] - v);
        return a;
    }

    int sumValues(const unordered_map<int,int>& count) {
        int sum = 0;
        for (auto& [k, v] : count) sum += v;
        return sum;
    }

    bool isSubset(const unordered_map<int,int>& a, const unordered_map<int,int>& b) {
        for (auto& [k, v] : a) {
            auto it = b.find(k);
            int bv = (it == b.end()) ? 0 : it->second;
            if (bv < v) return false;
        }
        return true;
    }

    pair<unordered_map<int,int>, bool> getPrimeCount(long long t) {
        unordered_map<int,int> count = {{2,0},{3,0},{5,0},{7,0}};
        for (int prime : {2,3,5,7}) {
            while (t % prime == 0) {
                t /= prime;
                count[prime]++;
            }
        }
        return {count, t == 1};
    }

    unordered_map<int,int> getPrimeCountFromString(const string& num) {
        unordered_map<int,int> count = {{2,0},{3,0},{5,0},{7,0}};
        for (char c : num) {
            int d = c - '0';
            for (auto& [prime, freq] : kFactorCounts[d]) count[prime] += freq;
        }
        return count;
    }

    unordered_map<int,int> getFactorCount(unordered_map<int,int> count) {
        unordered_map<int,int> res;
        int count8 = count[2] / 3;
        int remaining2 = count[2] % 3;
        int count9 = count[3] / 2;
        int count3 = count[3] % 2;
        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;
        int count6 = 0;
        if (count2 == 1 && count3 == 1) {
            count2 = 0; count3 = 0; count6 = 1;
        }
        if (count3 == 1 && count4 == 1) {
            count2 = 1; count6 = 1; count3 = 0; count4 = 0;
        }
        res[2] = count2;
        res[3] = count3;
        res[4] = count4;
        res[5] = count[5];
        res[6] = count6;
        res[7] = count[7];
        res[8] = count8;
        res[9] = count9;
        return res;
    }

    string construct(unordered_map<int,int>& factors) {
        string res;
        for (int digit = 2; digit < 10; digit++)
            res += string(factors[digit], char('0' + digit));
        return res;
    }

    string smallestNumber(string num, long long t) {
        auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        auto factorCount = getFactorCount(primeCount);
        if (sumValues(factorCount) > (int)num.size()) return construct(factorCount);

        auto primeCountPrefix = getPrimeCountFromString(num);
        int firstZeroIndex = -1;
        for (int i = 0; i < (int)num.size(); i++) {
            if (num[i] == '0') { firstZeroIndex = i; break; }
        }
        if (firstZeroIndex == -1) {
            firstZeroIndex = (int)num.size();
            if (isSubset(primeCount, primeCountPrefix)) return num;
        }

        for (int i = (int)num.size() - 1; i >= 0; i--) {
            int d = num[i] - '0';
            primeCountPrefix = subtract(primeCountPrefix, kFactorCounts[d]);
            int spaceAfterThisDigit = (int)num.size() - 1 - i;
            if (i > firstZeroIndex) continue;
            for (int biggerDigit = d + 1; biggerDigit < 10; biggerDigit++) {
                auto factorsAfterReplacement = getFactorCount(
                    subtract(subtract(primeCount, primeCountPrefix), kFactorCounts[biggerDigit])
                );
                if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
                    int fillOnes = spaceAfterThisDigit - sumValues(factorsAfterReplacement);
                    return num.substr(0, i) + char('0' + biggerDigit) + string(fillOnes, '1') + construct(factorsAfterReplacement);
                }
            }
        }

        auto factorsAfterExtension = getFactorCount(primeCount);
        return string(num.size() + 1 - sumValues(factorsAfterExtension), '1') + construct(factorsAfterExtension);
    }
};
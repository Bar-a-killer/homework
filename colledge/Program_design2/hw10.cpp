#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

enum class suit: short { SPADE, HEART, DIAMOND, CLUB };

class pips {
public: 
    pips(int val): v(val) { assert(v>0 && v<14); }
    friend ostream& operator<<(ostream& out, const pips& p);
    int get_pips() const { return v; }
private:
    int v;
};

class card {
public:
    card(): s(suit::SPADE), v(1) {}
    card(suit st, pips pv): s(st), v(pv) {}
    friend ostream& operator<<(ostream& out, const card& c);
    suit get_suit() const { return s; }
    pips get_pips() const { return v; }
private:
    suit s;
    pips v;
};

ostream& operator<<(ostream& os, const suit& s) {
   os << static_cast<std::underlying_type<suit>::type>(s);
   return os;
}

ostream& operator<<(ostream& os, const pips& p) {
    os << p.v; 
    return os; 
}

ostream& operator<<(ostream& os, const card& c) {
    os << "pips: " << c.v << ", suit: " << c.s << endl; 
    return os; 
}

void init_deck(vector<card> & d) {
    int i;
    for (i=1; i<14; i++) {
        card c(suit::SPADE, i);
        d[i-1] = c;
    }
    for (i=1; i<14; i++) {
        card c(suit::HEART, i);
        d[i+12] = c;
    }
    for (i=1; i<14; i++) {
        card c(suit::DIAMOND, i);
        d[i+25] = c;
    }
    for (i=1; i<14; i++) {
        card c(suit::CLUB, i);
        d[i+38] = c;
    }
}

void print(vector<card> &deck) {
    for (auto p=deck.begin(); p!=deck.end(); ++p) { // for (auto card_val: deck) cout << card_val
        cout << *p; 
    }
    cout << endl;
}

bool is_flush(vector<card> &hand) {
    suit s = hand[0].get_suit();
    for (auto p=hand.begin(); p!=hand.end(); ++p) {
        if (s != p->get_suit()) {
            return false;
        }
    }
    return true;
}

bool is_straight(vector<card> &hand) {
    sort(hand.begin(), hand.end(), [](const card& a, const card& b) 			
		{ return (a.get_pips()).get_pips() < (b.get_pips()).get_pips();} );

    int pips_v[5]; 
    int i = 0;
    for (auto p=hand.begin(); p!=hand.end(); ++p) {
        pips_v[i++] = (p->get_pips()).get_pips();
    }
    //sort(pips_v, pips_v+5);
    if (pips_v[0] != 1) { // not ACE
        return (pips_v[0] == pips_v[1]-1 && pips_v[1] == pips_v[2]-1) 
        && (pips_v[2] == pips_v[3]-1 && pips_v[3] == pips_v[4]-1); 
    } else {
        return (pips_v[0] == pips_v[1]-1 && pips_v[1] == pips_v[2]-1) 
        && (pips_v[2] == pips_v[3]-1 && pips_v[3] == pips_v[4]-1) 
        || (pips_v[1] == 10) && (pips_v[2] == 11) && (pips_v[3] == 12) 
        && (pips_v[4] == 13); 
    }
}

bool is_straight_flush(vector<card> &hand) {
    return is_flush(hand) && is_straight(hand);
}
vector<int> get_counts(vector<card> &hand) {
    map<int, int> freq;
    for (auto& c : hand)
        freq[c.get_pips().get_pips()]++;
    vector<int> counts;
    for (auto& p : freq)
        counts.push_back(p.second);
    sort(counts.rbegin(), counts.rend());
    return counts;
}
bool is_four_of_a_kind(vector<card> &hand) {
    vector<int> counts = get_counts(hand);
    if(counts[0] == 4) return 1;
    return 0;
}

bool is_full_house(vector<card> &hand) {
    vector<int> counts = get_counts(hand);
    if(counts[0] == 3 && counts[1] == 2) return 1;
    return 0;
}

bool is_three_of_a_kind(vector<card> &hand) {
    vector<int> counts = get_counts(hand);
    if(counts[0] == 3) return 1;
    return 0;
}

bool is_two_pair(vector<card> &hand) {
    vector<int> counts = get_counts(hand);
    if(counts[0] == 2 && counts[1] == 2) return 1;
    return 0;
}

bool is_one_pair(vector<card> &hand) {
    vector<int> counts = get_counts(hand);
    if(counts[0] == 2) return 1;
    return 0;
}
int main()
{
    int m,s;
    cin >> m >> s;
    vector<card> deck(52);
    srand(s); 
    init_deck(deck);
    map<string, int> rankings;
    rankings["1_Straight Flush"] = 0;
    rankings["2_Four of a Kind"] = 0;
    rankings["3_Full House"]     = 0;
    rankings["4_Flush"]          = 0;
    rankings["5_Straight"]       = 0;
    rankings["6_Three of a Kind"] = 0;
    rankings["7_Two Pair"]       = 0;
    rankings["8_One Pair"]       = 0;
    rankings["9_High Card"]      = 0;
    for (int loop = 0; loop < m; ++loop) {
        random_shuffle(deck.begin(), deck.end());
        vector<card> hand(deck.begin(), deck.begin() + 5);

        if      (is_straight_flush(hand))  rankings["1_Straight Flush"]++;
        else if (is_four_of_a_kind(hand))  rankings["2_Four of a Kind"]++;
        else if (is_full_house(hand))      rankings["3_Full House"]++;
        else if (is_flush(hand))           rankings["4_Flush"]++;
        else if (is_straight(hand))        rankings["5_Straight"]++;
        else if (is_three_of_a_kind(hand)) rankings["6_Three of a Kind"]++;
        else if (is_two_pair(hand))        rankings["7_Two Pair"]++;
        else if (is_one_pair(hand))        rankings["8_One Pair"]++;
        else                               rankings["9_High Card"]++;
    }

    for (auto& p : rankings) {
        if (p.first[0] == '9') continue;
        cout << p.first.substr(2) << ": " << p.second << "\n";
    }
    
    return 0;
}


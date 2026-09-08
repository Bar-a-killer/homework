#include<bits/stdc++.h>

class Country{
    public:
    int voters[100];
    static int candidateAType,candidateBType;
    static int votesForA,votesForB;
    void inputVoters(int numVoters) {
        std::cout << "Enter types for voters: \n";
        for(int i=0;i<numVoters;i++){
            std::cin >> voters[i];
        }
    }
    static void inputCandidates() {
        std::cout << "Enter type for candidate A: \n";
        std::cin >> candidateAType;
        std::cout << "Enter type for candidate B: \n";
        std::cin >> candidateBType;
    }
    void castVotes(int numVoters) {
        for(int i=0;i<numVoters;i++){
            bool voteA = abs(voters[i] - candidateAType) 
                        <= abs(voters[i] - candidateBType);
            if(voteA){
                votesForA++;
            }
            else {
                votesForB++;
            }
        }
    }
    void outputWinner() {
        if(votesForA > votesForB){
            std::cout << "Candidate A wins with " << votesForA << " votes." << std::endl;
        }
        else if(votesForB > votesForA){
            std::cout << "Candidate B wins with " << votesForB << " votes." << std::endl;
        }
        else {
            std::cout << "It's a tie with " << votesForA << " votes each." << std::endl;
        }
    }
};
int Country::candidateAType = 0;
int Country::candidateBType = 0;
int Country::votesForA = 0;
int Country::votesForB = 0;
int main(){
    Country country;
    int numVoters;
    std::cout << "number of voters: ";
    std::cin >> numVoters;
    country.inputVoters(numVoters);
    Country::inputCandidates();
    country.castVotes(numVoters);
    country.outputWinner();
    return 0;
}
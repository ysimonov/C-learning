#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>

int LevenshteinDistance(std::string string1, std::string string2) {
    int M = string1.length(); 
    int N = string2.length();
    int* dist = new int[M * N]; // array M x N
    int substitutionCost = 0;
    int i, j, im, jm;
    int result;
    int deletion_and_insertion;

    // arr[i][j] -> arr[i*N+j]

    for (i=0; i<M; i++) {
        dist[i*N] = i;
    }

    for (j=0; j<N; j++) {
        dist[j] = j;
    }

    for (i=1; i<M; i++) {
        im = i-1;
        for (j=1; j<N; j++) {
            jm = j-1;
            if (string1[im] == string2[jm]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            // deletion, insertion and substitution
            deletion_and_insertion = std::min(dist[im*N+j]+1, dist[i*N+jm]+1);
            dist[i*N+j] = std::min(deletion_and_insertion, dist[im*N+jm]+substitutionCost);
        }
    }

    result = dist[(M-1)*N+(N-1)];
    delete [] dist;

    return result;
}

int main(void) {

    std::string string1;
    std::string string2;
    int result;

    std::cout << "Enter first string: ";
    std::getline(std::cin, string1);

    std::cout << "Enter second string: ";
    std::getline(std::cin, string2);

    result = LevenshteinDistance(string1, string2);

    std::cout << "Levenshtein distance of " << string1 << " and " << string2 << " is " << result << std::endl;

    return EXIT_SUCCESS;
}
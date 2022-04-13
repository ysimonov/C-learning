#include <iostream>
#include <string>
#include <algorithm>

int LevenshteinDistance(std::string string1, std::string string2) {

    int M = string1.length(); 
    int N = string2.length();
    int* dist = new int[M * N]; // array M x N
    int substitutionCost = 0;
    int i, j;
    int result;
    int deletion_and_insertion;

    // arr[i][j] -> arr[i*N+j]

    for (i=0; i<M; i++) {
        dist[i*N] = i;
    }

    for (j=0; j<N; j++) {
        dist[j] = j;
    }

    for (j=1; j<N; j++) {
        for (i=1; i<M; i++) {
            if (string1[i-1] == string2[j-1]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            // deletion, insertion and substitution
            deletion_and_insertion = std::min(dist[(i-1)*N+j]+1, dist[i*N+(j-1)]+1);
            dist[i*N+j] = std::min(deletion_and_insertion, dist[(i-1)*N+(j-1)]+substitutionCost);
            // std::cout << dist[i][j] << std::endl;
        }
    }

    result = dist[(M-1)*N+(N-1)];

    std::cout << "result: " << result << std::endl;
    delete [] dist;

    return result;
}

int main(void) {

    std::string string1;
    std::string string2;
    int result;

    std::cout << "Enter first string: ";
    std::cin >> string1;

    std::cout << "Enter second string: ";
    std::cin >> string2;

    result = LevenshteinDistance(string1, string2);

    std::cout << "Levenshtein distance of " << string1 << " and " << string2 << " is " << result << std::endl;

    return EXIT_SUCCESS;
}
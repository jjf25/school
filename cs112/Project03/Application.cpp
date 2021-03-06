/* Application.cpp: Runs application interface
 * Student Name: Joey Faas, Ian Park
 * Date: 9/27/17
 */

#include "Application.h"

Application::Application() {
}

void Application::run() {
    cout << "Welcome to the vector program!" << endl;
    cout << "Please enter the number of dimension: " << flush;
    unsigned dim, numVectors;
    cin >> dim;
    cout<< "Please enter the " << dim <<" coordinates of the starting location: " << endl;
    Vec start(dim);

    for (unsigned i = 0; i < dim; i++) {
        cin >> start[i];
    }
    cout << "How many vectors will there be? " << endl;
    cin >> numVectors;
    for (unsigned i = 0; i < numVectors; i++) {
        Vec add(dim);
        cout << "Please enter " << dim << " numbers for the " << i << "th vector of the " <<  numVectors
                << " vectors: " << endl;
        for (unsigned i = 0; i < dim; i++) {
            cin >> add[i];
        }

        start = start + add;
    }

    cout << "The coordinates of this vector are: {" << flush;
    for (unsigned i = 0; i < dim; i++) {
        if (dim != 1 && i != dim - 1) {
            cout << start[i] << ", ";
        } else {
            cout << start[i];
        }
    }
    cout << "}" << endl;
}


# README for Publication Tracker

## Program Description
This assignment tracks publications based on research at an institute. It models publication data, parses a `.bib` file, and allows searching for an author's publications. It also calculates the average number of co-authors for each publication.

## Files
- `publication.h/.cpp`: Defines the publication structure.
- `bibparser.h/.cpp`: Parses `.bib` files and validates the data.
- `question2.cpp`: Constructs data from a `.bib` file and validates it.
- `question3.cpp`: Allows querying publications by an author and calculates co-author averages.
- `Makefile_P2` and `Makefile_P3`: Automate compilation for Question 2 and 3.
- `Bibfile` : containing publications
- `Faculty_Affiliations.csv`: List of institute faculty for validation.

## How to Compile and Run

### Compile Question 2
Run the following command to compile Question 2:
```
make -f Makefile_P2 test
```
This will generate the executables:
- `question2_debug` (debug version)
- `question2_optimized` (optimized version)

### Compile Question 3
Run the following command to compile Question 3:
```
make -f Makefile_P3 test
```
This will generate the executables:
- `question3_debug` (debug version)
- `question3_optimized` (optimized version)

### Run the Programs
- **Question 2**: 
  - Debug version: `./question2_debug`
  - Optimized version: `./question2_optimized`

- **Question 3**: 
  - Debug version: `./question3_debug [author name]`
  - Optimized version: `./question3_optimized [author name]`

### Note
Ensure the `.bib` file and `faculty.csv` are in the same directory as the program. Invalid `.bib` files will trigger assertions.

# References
from google and some AI tools
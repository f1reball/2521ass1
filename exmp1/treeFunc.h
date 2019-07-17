void test(InvertedIndexBST tree);

InvertedIndexBST createNewTree(void);

InvertedIndexBST createNewNode(char *word, char *filename);

InvertedIndexBST addnew(InvertedIndexBST tree, char *data, char *filename);

void showNode(InvertedIndexBST tree, FILE *fp);

void printlist(FileList list, FILE *fp);

InvertedIndexBST nodefind(InvertedIndexBST tree, char *word);

int wordcount(InvertedIndexBST tree, char *word);

TfIdfList addtolist(TfIdfList list, char *filename, double tf);

double scanforallwords(InvertedIndexBST tree, char * filename);

TfIdfList orderingtf(TfIdfList list);

int findinlist(TfIdfList list, char * word);

TfIdfList editlist(TfIdfList list, char * filename, double value);

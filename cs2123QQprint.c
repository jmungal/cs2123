#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "cs2123p5.h"

/******************** prettyPrint ****************************************
<<<<<<< HEAD
void prettyPrint(NodeT *p, int iIndent)
 Purpose: Helper function to printPriceMenu. Recursively prints all items of the
          price menu
 
 Parameters:
 I/O     NodeT *p                Pointer to node for requested Id.
 I       int iIndent             Keeps track of necessary indentions to print prettily.
 
 Returns:
    N/A
 
 Notes:
    Work horse to printPriceMenu function
 **************************************************************************/
void prettyPrint(NodeT *p, int iIndent)
{
    int i;
    
    if(p == NULL)
        return; 
    
    prettyPrint(p->pChild, iIndent + 1);
    printf("\t");

    for (i = 0; i < iIndent; i++)
        printf("\t");
    //if it does not have a cost print just the item title
    if (p->element.cCostInd == 'N')
        printf("%s\n", p->element.szTitle);
    // if it does have a value print both item title and its cost 
    else
        printf("%s%.2lf\n", p->element.szTitle, p->element.dCost);
    prettyPrint(p->pSibling, iIndent + 1);
}


/********************printPriceMenu******************************
 void printPriceMenu(Tree tree)
 Purpose: Prints the contents of the tree in a readable style
 
 Parameters:
 I    Tree tree	Struct containing the Root and Nodes of a tree
 
 Returns:
 N/A
 
 Notes:

 iIndent will be modified in the prettyPrint function to keep track of indention
 **************************************************************************/
void printPriceMenu(Tree tree)
{
    int iIndent;
    iIndent = 0;
    
    prettyPrint(tree->pRoot, iIndent);
}

/******************** printOne ****************************************
 void printOne(Tree tree, char szId[])
 Purpose: Prints out one item from selected pointer
 
 Parameters:
 I       Tree tree               Menu to be printed from
 I       char szId[]             Item to be printed
 
 Returns:
 N/A
 
 Notes:
 Will print an error but continue program if selected item is not found.
 **************************************************************************/

void printOne(Tree tree, char szId[])
{
    NodeT *p;
    p = findId(tree->pRoot, szId);

    if (p == NULL)
        printf("ERROR ID %s NOT FOUND\n", szId);
    else 
        printf("Title: %s Cost: %.2lf\n", p->element.szTitle, p->element.dCost);
}

#include "PQL/tree_util.hh"
#include "PQL/PQLNode.h"
#include "PQL/PQLTree.h"
#include "QueryPreProcessor.h"
#include "Validator/Validator.h"
#include "PQL/PQL.h"

using namespace std;

int main(int argc, char** args) {
	Validator* v = new Validator();
	QueryPreProcessor* que = new QueryPreProcessor();
	PQL *pql = new PQL();
	pql->enterQuery();
	pql->processQuery(pql->getQuery());
	//string a = "assign a; select a such that follows(a,\"a\");";
	cout << "**** ZAPYTANIE **************************************************" << endl;
	cout << pql->getQuery()<< endl << endl;
	cout << "**** DRZEWO *****************************************************" << endl;
	que->parseQuery(pql->getQuery());
	tree<tree_node_<PQLNode>>::iterator iter;
	PQLTree* tree = que->getTree();
	tree->printTree();
	cout << endl;
	cout << "**** KONIEC DRZEWA*****************************************************" << endl;
	cout << "**** WALIDACJA TESTY - KRZYSIEK****************************************" << endl;
	cout << v->checkSelect("select dgdd 4 23") << endl;
    cout << v->checkSelect("select select dgdd 4 23") << endl;
    cout << v->checkRelationship("modifies(procedure,variable)") << endl;
    cout << v->checkAttribute("procedure.procname") << endl;
	cout << "**** WALIDACJA TESTY - KONIEC****************************************" << endl;

	// DRZEWO PQL
	/*
	tree<tree_node_<PQLNode>>::iterator iter;
	PQLTree* tree;
	tree = tree->getInstance();
	PQLNode* node;
	tree_node_<PQLNode>* treeNode;

	// assign a; select a such that parent(a,2) and follows*(_,a);

	node = new QueryNode();
	treeNode = new tree_node_<PQLNode>(*node);
	iter = tree->appendRoot(*treeNode);

	node = new ResultMainNode();
	treeNode = new tree_node_<PQLNode>(*node);
	iter = tree->appendChild(iter, *treeNode);

	node = new ResultNode(new Field("assign", "a", false, false, false));
	treeNode = new tree_node_<PQLNode>(*node);
	iter = tree->appendChild(iter, *treeNode);

	iter = tree->getRoot();

	node = new SuchMainNode();
	treeNode = new tree_node_<PQLNode>(*node);
	iter = tree->appendChild(iter, *treeNode);

	node = new SuchNode("parent", new Field("assign", "a", false, false, false), new Field("constant", "2", false, false, false), false);
	treeNode = new tree_node_<PQLNode>(*node);
	iter = tree->appendChild(iter, *treeNode);

	node = new SuchNode("follows", new Field("all", "_", false, false, false), new Field("assign", "a", false, false, false), true);
	treeNode = new tree_node_<PQLNode>(*node);
	iter = tree->appendSibling(iter, *treeNode);

	tree->printTree();
	*/
	//string a = "assign a, a2; prog_line p; select a, p.procname such that parent(a,2) and follows*(\"ala\",a2) such that uses(_,p) such that modifies*(2,p);";
	//string a = "assign a; select a such that follows(a,\"a\") such that parent(a,a);";

	//cout << tree->getRoot()->data.type << endl;

	//PQLNode p = tree->getRoot()->data;
	//cout << typename;
	//cout << endl;
	//ResultNode q = static_cast<ResultNode>(tree->getRoot()->first_child->first_child->data.type);
	//q.getField()->printField();

	return 0;
}

#include <iostream>
using namespace std;
//��������㶨��  
struct BinaryTreeNode  
{  
    int Value;  
    BinaryTreeNode* Left;  
    BinaryTreeNode* Right;  
};  
  
//�������������  
BinaryTreeNode* CreateBinaryTreeNode(int value)  
{  
    BinaryTreeNode* pNode = new BinaryTreeNode();  
    pNode->Value = value;  
    pNode->Left = NULL;  
    pNode->Right = NULL;  
    return pNode;  
}  
  
//���������  
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)  
{  
    if (pParent != NULL)  
    {  
        pParent->Left = pLeft;  
        pParent->Right = pRight;  
    }  
}  
  
//�������  
void InOrderPrintTree(BinaryTreeNode* pRoot)  
{  
    if (pRoot != NULL)  
    {  
        //�������  
        if (pRoot->Left != NULL)  
        {  
            InOrderPrintTree(pRoot->Left);  
        }  
        //��  
        cout << "value of this node is " << pRoot->Value << endl;  
        //�����ұ�  
        if (pRoot->Right != NULL)  
        {  
            InOrderPrintTree(pRoot->Right);  
        }  
  
    }  
    else  
    {  
        cout << "this node is null." << endl;  
    }  
  
}  
  
//ת�����������Ϊ˫������  
void Convert(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeLnList)  
{  
    if (pNode == NULL)  
    {  
        return;  
    }  
  
    BinaryTreeNode* pCurrent = pNode;  
  
    //������ת������������������Ҷ�ӽ��  
    if (pCurrent->Left != NULL)  
    {  
        Convert(pCurrent->Left, pLastNodeLnList);  
    }  
    pCurrent->Left = *pLastNodeLnList;  
    if ((*pLastNodeLnList) != NULL)  
    {  
        (*pLastNodeLnList)->Right = pCurrent;  
    }  
    *pLastNodeLnList = pCurrent;  
  
    //������ת��  
    if (pCurrent->Right != NULL)  
    {  
        Convert(pCurrent->Right, pLastNodeLnList);  
    }  
  
}  
  
//��ȡ˫������ͷ���  
BinaryTreeNode* Convert(BinaryTreeNode* pRoot)  
{  
    //ָ��˫�������β���  
    BinaryTreeNode* pLastNodeInList = NULL;  
    //ת�����������Ϊ˫������  
    Convert(pRoot, &pLastNodeInList);  
  
    //��˫�������ͷ���  
    BinaryTreeNode* pHeadOfList = pLastNodeInList;  
    while (pHeadOfList!=NULL&&pHeadOfList->Left!=NULL)  
    {  
        pHeadOfList = pHeadOfList->Left;  
    }  
    return pHeadOfList;  
}  
  
//��ӡ˫������  
void PrintList(BinaryTreeNode* pRoot)  
{  
    BinaryTreeNode* pNode = pRoot;  
  
    while (pNode!=NULL)  
    {  
        cout << pNode->Value << "    ";  
        pNode = pNode->Right;  
    }  
  
    cout << endl;  
    cout << "PrintList ends." << endl << endl;  
  
}  
  
  
// ====================���Դ���====================  
void Test1()  
{  
//                 10  
//              /      \  
//            6        14  
//           /\        /  \  
//          4  8      12  16  
  
    cout << "The Test1:" << endl;  
  
   //���������  
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);  
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);  
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);  
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);  
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);  
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);  
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);  
  
    //���������  
    ConnectTreeNodes(pNode10, pNode6, pNode14);  
    ConnectTreeNodes(pNode6, pNode4, pNode8);  
    ConnectTreeNodes(pNode14, pNode12, pNode16);  
  
    //�������  
    InOrderPrintTree(pNode10);  
    //��ȡ˫������ͷ���  
    BinaryTreeNode* pHeadOfList = Convert(pNode10);  
    //�������  
    PrintList(pHeadOfList);  
  
}  
  
void Test2()  
{  
    //               5  
    //              /  
    //             4  
    //            /  
    //           3  
    //          /  
    //         2  
    //        /  
    //       1  
  
    cout << "The Test2:" << endl;  
    //���������  
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);  
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);  
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);  
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);  
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);  
      
    //���������  
    ConnectTreeNodes(pNode5, pNode4,NULL);  
    ConnectTreeNodes(pNode4, pNode3, NULL);  
    ConnectTreeNodes(pNode3, pNode2, NULL);  
    ConnectTreeNodes(pNode2, pNode1, NULL);  
  
    //�������  
    InOrderPrintTree(pNode5);  
    //��ȡ˫������ͷ���  
    BinaryTreeNode* pHeadOfList = Convert(pNode5);  
    //�������  
    PrintList(pHeadOfList);  
  
}  
  
void Test3()  
{  
// 1  
//  \  
//   2  
//    \  
//     3  
//      \  
//       4  
//        \  
//         5  
  
    cout << "The Test3:" << endl;  
    //���������  
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);  
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);  
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);  
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);  
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);  
      
    //���������  
    ConnectTreeNodes(pNode1, NULL, pNode2);  
    ConnectTreeNodes(pNode2, NULL, pNode3);  
    ConnectTreeNodes(pNode3, NULL, pNode4);  
    ConnectTreeNodes(pNode4, NULL, pNode5);  
  
    //�������  
    InOrderPrintTree(pNode1);  
    //��ȡ˫������ͷ���  
    BinaryTreeNode* pHeadOfList = Convert(pNode1);  
    //�������  
    PrintList(pHeadOfList);  
  
}  
  
void Test4()  
{  
  // ����ֻ��1�����  
  
    cout << "The Test4:" << endl;  
   //���������  
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);  
  
    //���������  
    ConnectTreeNodes(pNode1, NULL, NULL);  
  
    //�������  
    InOrderPrintTree(pNode1);  
    //��ȡ˫������ͷ���  
    BinaryTreeNode* pHeadOfList = Convert(pNode1);  
    //�������  
    PrintList(pHeadOfList);  
  
}  
  
void Test5()  
{  
   // ����û�н��  
  
    cout << "The Test5:" << endl;  
    //���������  
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(NULL);  
  
    //���������  
    ConnectTreeNodes(pNode1, NULL, NULL);  
  
    //�������  
    InOrderPrintTree(pNode1);  
    //��ȡ˫������ͷ���  
    BinaryTreeNode* pHeadOfList = Convert(pNode1);  
    //�������  
    PrintList(pHeadOfList);  
  
}  
  
//void main()  
//{  
//    Test1();  
//    Test2();  
//    Test3();  
//    Test4();  
//    Test5();  
//    system("pause");  
//}  
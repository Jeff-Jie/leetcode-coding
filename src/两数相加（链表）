/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}      //这是带初始化列表的构造函数，创建一个数据为x，指向下一个结点的指针为空，也就是没有下一个结点的                                                     //链表，其实创建一个链表，只要创建头结点和next指针即可。
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //给定两个非空链表，要返回一个新链表
        /*链表是什么？我们可以将一条链表想象成环环相扣的结点，就如平常所见到的锁链一样。链表内包含很多结点（当然也可以包含零个结点）。其中每个结点的数据空间一般会包含一个数据结构（用于存放各种类型的数据）以及一个指针，该指针一般称为next，用来指向下一个结点的位置。由于下一个结点也是链表类型，所以next的指针也要定义为链表类型*/
        //形参中l1表示第一个链表的头结点，l2表示第二个链表的头结点
        //看上面定义的链表节点 结构体，发现链表节点包括数据结构和一个指针。
        
        //这道题采用递归法较好：
        if (l1 == null || l2 == null){   //形参是声明了一个链表节点指针，即链表头结点的地址，链表l1  或者  l2为空链表时
            return l1 == null ? l2:l1;   //如果l1为空链表，那么l1链表加上l2链表的结果就是l2，返回l2即可，否则返回l1
        }
        int value = l1.val + l2.val;     //定义两个链表对应结点相加的和为value，val是在结构体中定义好的，表示节点中的数据
        ListNode result = new ListNode(value % 10);   //result是该函数最后要返回的链表，开辟一个链表空间，也就是创建了一个链表，该链表头结点的数据                                                   //是value % 10 （求余，即9%10 = 9），next指针目前是空的，也就是该链表只有头结点，值为value%10
        
       
    }
};


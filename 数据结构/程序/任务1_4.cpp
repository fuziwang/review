int list_len(LinkList L)
{
    LinkList p = L->next;
    if(p != NULL)
        return 1 + list_len(p);
    else
        return 1;
}
/*	时间复杂度：O(n)	空间复杂度O(n)*/
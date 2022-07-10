int GetNode(Node *head,int positionFromTail)
{
    int range = -1;
    int res = 0;
    Node * tracer = head;
    while (head)
    {
        head = head->next;        
        if(range < positionFromTail)
            range++;
        else
            tracer = tracer->next;
    }
    res = tracer->data;
    return res;
}
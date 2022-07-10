## https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem

def has_cycle(head):
    visited = {}
    while head:
        visited[head]=1
        if visited.get(head.next,0) != 0:
            return True
        head = head.next
    return False
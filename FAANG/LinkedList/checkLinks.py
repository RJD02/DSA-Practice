class Node:
  def __init__(self, val=None, prev=None, 
                next=None, child=None):
    self.val = val
    self.next = next
    self.prev = prev
    self.child = child

null = None

def makeLists(array):
  '''
  Recursively generates the complete graph from given serialization
  Parameter:
    array - serialization of the list as Python list
  Returns:
    head to the top most list (first node of the
    graph)
  '''
  head = None
  prev = None
  i = 0
  while i < len(array):
    if array[i] != null:
      node = Node(val=array[i], prev=prev)
      if prev is None:
        head = prev = node
      else:
        prev.next = node
        prev = node
      i += 1
    else:
      node = head
      end = False
      while array[i] == null:
        if node.next is None:
          end = True
        else:
          node = node.next
        i += 1
      if end:
        node.child = makeLists(array[i:])
      else:
        node.prev.child = makeLists(array[i:])
      break
  return head

def strLists(head, lists):
  '''
  Helper function to recursively serialize the graph prior to visualization. It's an interim step and
  only meant to be called by the printLists function.

  Parameters:
    head - head of the present list 
    lists - the serialization being built recursively (passed by reference)

  Returns:
    None (lists is updated in place). 
  '''
  if head is None:
    return
  nodes = []
  while head:
    nodes.append(str(head.val))
    if head.child is not None:
      nodes.append('|')
      strLists(head.child, lists)
    head = head.next
  lists.append(nodes)

def printLists(head):
  '''
  Visualizes the entire graph
  Parameter:
    head - the top most Node
  '''
  lists = []
  strLists(head, lists)
  if lists == []:
    print(None)
    return
  previndent = 0
  for j, l in enumerate(lists[::-1]):
    count = -1
    indent = 0
    s = []
    for i in range(len(l)):
      if l[i] != '|':
        s.append(l[i])
        count += 1
      else:
        indent = count * 4
        child = count
    print('---'.join(s)) 
    if  len(lists) > 1 and j < len(lists) - 1:
      previndent += indent
      indentation = ''.join([' '] * previndent)
      if len(l[0]) > 1:
        indentation += ''.join([' '] * child)
      print(indentation + '|')
      print(indentation, end='')

def checkLinks(head, lists=None):
  '''
  Verifies that all lists can be traversed in both directions.

  Parameter:
    head - top most Node

  Returns:
    Boolean, True if all lists traversable, False if not.
  '''
  if head is None:
    return True
  if lists is None:
    lists = []
  stack = []
  result = True
  node = head
  while node is not None:
    if node.child is not None:
      checkLinks(node.child, lists)
    stack.append(node)
    prev = node
    node = node.next
  while prev is not None:
    if len(stack) == 0 or stack.pop() != prev:
      result = False
    prev = prev.prev
  lists.append(result)
  return all(lists)


# Example to show usage
array = [1,null,2,null,3,null]

head = makeLists(array)
printLists(head)
print(checkLinks(head))
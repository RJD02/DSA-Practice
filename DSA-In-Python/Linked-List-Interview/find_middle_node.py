'''

Given head of a linked list, construct an in-place algorithm that's able to find the middle node

1 -> 2 -> |3| -> 4 -> 5 -> null
Output: 3

|1| -> null
Output: 1

null
Output: null

Brute force solutio:
	Store all the contents of list into an array, then find the middle node->data

Since I am given only head, I have no option but to traverse the whole SLL.
How to know this is the middle node?
To get the middle node, I have to know what is the end position


So, in the first iteration, I can get to know the size of the list
Then, by getting the length, I can find the middle position
Then, again traverse the list, till that position arrives
Time complexity: O(2 * n) ==~~ O(n)

Efficient Approach:
Use slow-fast pointers
Use two pointers,
first which traverses with step of 1
second which traverses with step of 2
As soon as second reaches the END NODE, the first reaches the middle node
Time complexity: O(n)
'''

class Node:
	def __init__(self, value):
		self.val = value
		self.next = None

class List:
	def __init__(self, value):
		self.head = Node(value)
		self.head.next = None

	def addNode(self, value):
		temp = Node(value)
		if self.head == None:
			self.head = temp
			return
		currentNode = self.head
		while currentNode.next != None:
			currentNode = currentNode.next
		currentNode.next = temp


def get_middle_node_1(a):
	head = a.head
	length = 0
	currentNode = head
	while currentNode:
		length += 1
		currentNode = currentNode.next
	mid_val = length // 2
	currentNode = head
	while currentNode and mid_val:
		mid_val -= 1
		currentNode = currentNode.next
	return currentNode.val


def get_middle_node(a):
	head = a.head
	first = head
	second = head
	while second.next and second.next.next:
		first = first.next
		second = second.next.next
	return first.val



def main():
	a = List(1)
	a.addNode(2)
	a.addNode(3)
	a.addNode(4)
	# a.addNode(5)
	# a.addNode(6)
	# a.addNode(7)
	# print(get_middle_node_1(a))
	print(get_middle_node(a))

if __name__ == '__main__':
	main()

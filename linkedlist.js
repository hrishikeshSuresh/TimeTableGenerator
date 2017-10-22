function Node(data,next)
{
  this.data = data;
  this.next = next;
}

function LinkedList()
{
  this.head = null;
  this.size = null;
}

LinkedList.push = function(data)
{
  new_node = new Node(data);
  if(this.size == 0)
  {
    this.head = new_node;
  }
  this.size++;
  return this;
}

LinkedList.print = function()
{
  document.write=Array.toString(list.toArray());
}

var list = new LinkedList();
list.push('first');
list.push('second');
list.push('third');

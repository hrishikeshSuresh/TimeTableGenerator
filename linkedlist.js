function Node(data)
{
  this.data = data;
  this.next = null;
}

function LinkedList()
{
  this.head = null;
  this.size = null;
}

LinkedList.prototype.push = function(data)
{
  var current = this.head;
  var new_node = new Node(data);
  if(!current)
  {
    this.head = new_node;
    this.size++;
    return new_node;
  }
  while(current.next!=null)
  {
    current = current.next;
  }
  current.next = new_node;
  this.size++;
  return this;
}

LinkedList.prototype.print = function()
{
  //document.write=Array.toString(list.toArray());
  var current = this.head;
  document.write("<ul>")
  while(current!=null)
  {
    document.write("<li>",current.data);
    document.write("</li>");
    current = current.next;
  }
  document.write("</ul>");
}

LinkedList.prototype.deleteWithName =  function(name)
{
  var p = this.head;
  var q;
  while(p!=null)
  {
    if(p.data == name)
    {
      q = p.next;
      this.head = q;
      return this;
    }
    q = p;
    p = p.next;
  }
}

var list = new LinkedList();
list.push(1);
list.push(2);
list.push(3);
list.print();
list.deleteWithName(1);
list.print();

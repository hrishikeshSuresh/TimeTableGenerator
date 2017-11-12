function Node(data_name,subject,hours)
{
  this.data = data_name;
  this.subject = subject;
  this.hours = hours;
  this.next = null;
}

function LinkedList()
{
  this.head = null;
  this.size = null;
}

LinkedList.prototype.push = function(data_name,subject,hours)
{
  var current = this.head;
  var new_node = new Node(data_name,subject,hours);
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

LinkedList.prototype.lengthOfList = function()
{
  var current = this.head;
  var l = 0;
  while(current.next!=null)
  {
    l = l + 1;
    current = current.next;
  }
  return l;
}

LinkedList.prototype.printName = function()
{
  //document.write=Array.toString(list.toArray());
  var current = this.head;
  document.write("<ul>")
  while(current.next!=null)
  {
    document.write("<li>",current.data);
    document.write("</li>");
    current = current.next;
  }
  document.write("</ul>");
}

LinkedList.prototype.printSubject = function()
{
  //document.write=Array.toString(list.toArray());
  var current = this.head;
  document.write("<ul>")
  while(current.next!=null)
  {
    document.write("<li>",current.subject);
    document.write("</li>");
    current = current.next;
  }
  document.write("</ul>");
}

LinkedList.prototype.printHours = function()
{
  //document.write=Array.toString(list.toArray());
  var current = this.head;
  document.write("<ul>")
  while(current.next!=null)
  {
    document.write("<li>",current.hours);
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
      q.next = p.next;
      return this;
    }
    q = p;
    p = p.next;
  }
}

LinkedList.prototype.retrieveHead = function ()
{
    var current = this.head;
    return current;
}

LinkedList.prototype.getName = function(current)
{
  document.write(current.data_name);
}

LinkedList.prototype.imp = function ()
{
  
};
var list = new LinkedList();

/*function LinkedList(){
  this.head = null;
}
LinkedList.prototype.push = function(val){
    var node = {
       value: val,
       next: null
    }
    if(!this.head){
      this.head = node;
    }
    else{
      current = this.head;
      while(current.next){
        current = current.next;
      }
      current.next = node;
    }
let ll = new LinkedList();
document.write(ll.head);  //Object value: 235
document.write(ll.head.next); //Object value: 245
document.write(ll.head.next.next); //object value: 123
}*/
function Node(value, next)
{
  this.value = value;
  this.next = next;
}

// TODO - Only expose this to global
function LinkedList()
{
  this.first = null;
  this.last = null;
  this.size = 0;
}

LinkedList.print = function()
{
  var current = this.first;
  while (current !== null)
  {
    document.write(current);
    current = current.next;
  }
}


LinkedList.append = function(value)
{
  var node = new Node(value);
  if (this.size === 0)
  {
    this.first = node;
  }
  else
  {
    this.last.next = node;
  }
    this.last = node;
    this.size++;
    return this;
}

function Iterator(list)
{
  this.list = list;
  this.index = list.first;
}

Iterator.hasNext = function()
{
  return this.index !== null && this.index.next !== null;
}

Iterator.next = function() {
  var nextNode = this.index;
  while(nextNode.next!=undefined)
  {
    document.write(nextNode.value);
    this.index = nextNode;
  }
  return this.index;
}

var list = new LinkedList();

list.append('first');
list.append('second');
list.append('third');

var i = new Iterator(list);

while(i.hasNext()) {
    i.next();
}

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
function Node(value, next) {
  this.value = value;
  this.next = next || null;
}

// TODO - Only expose this to global
function LinkedList() {
  this.first = null;
  this.last = null;
  this.size = 0;
}

LinkedList.prototype.iterate = function(callback) {
  var current = this.first;

  while (current !== null) {
    callback.call(this, current);
    current = current.next;
  }
}


LinkedList.prototype.append = function(value) {

    var node = new Node(value);

    if (this.size === 0) {
        this.first = node;
    } else {
        this.last.next = node;
    }

    // node.next = null;
    this.last = node;
    this.size++;
    return this;
}

function Iterator(list) {
  this.list = list;
  this.index = list.first;
}

Iterator.prototype.hasNext = function() {
  return this.index !== null && this.index.next !== null;
}

Iterator.prototype.next = function() {
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

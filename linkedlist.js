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
      q.next = p.next;
      return this;
    }
    q = p;
    p = p.next;
  }
}

var list = new LinkedList();
document.write("Insert working!")
list.push("Senor Pink");
list.push("Monkey D. Luffy");
list.push("Silvers Raleigh");
list.push("Eustass Kidd");
list.push("Jimbei");
list.print();
document.write("Delete works!")
list.deleteWithName("Silvers Raleigh");
list.print();
/*import System.IO;

$.ajax({ url: 'teachers_data.csv', dataType: 'text', }).done(timeTableGenerator);
function timeTableGenerator(data)
{
  var file = "teachers_data_timetable.csv"
  var allRows = data.split(/\r?\n|\r/);
  for (var singleRow = 0; singleRow < allRows.length; singleRow++)
  {
    var rowCells = allRows[singleRow].split(',');
    for ( var rowCellCount = 0;rowCellCount < rowCells.length; rowCells++)
    {
      list.push(rowCells);
      list.print();
      document.write = rowCells[rowCellCount];
    }
  }
}*/

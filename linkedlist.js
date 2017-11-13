function Node(data,subject,hours)
{
  this.data = data;
  this.subject = subject;
  this.hours = hours;
  this.next = null;
}

function LinkedList()
{
  this.head = null;
  this.size = null;
}

LinkedList.prototype.push = function(data,subject,hours)
{
  var current = this.head;
  var new_node = new Node(data,subject,hours);
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

list = new LinkedList();

$.ajax({ url: 'teachers_data.csv', dataType: 'text', }).done(LinkedList.prototype.readData);
LinkedList.prototype.readData = function(data)
{
  var allRows = data.split(/\r?\n|\r/);
  for (var singleRow = 0; singleRow < allRows.length; singleRow++)
  {
  var rowCells = allRows[singleRow].split(',');
  list.push(rowCells[0],rowCells[1],rowCells[2]);
  }
  alert('Data read!');
}
LinkedList.prototype.Generate = function()
{
  for(var i=0;i<=5;i++)
    {
      document.write("Im pissed!");
      var current = this.head;
      document.write(current.subject);
      for(var j=0;j<=5;j++)
      {
        var l = list.lengthOfList();
        var r = Math.floor(Math.random()*(l-1));
        var k = 0;
        while(k!=r && current.next!=null)
        {
          current = current.next;
          document.write(current.data);
          k = k + 1;
        }
        if(current.hours == 0)
        {
          list.deleteWithName(current.data);
          current = this.head;
        }
        if(l==0)
          alert("Insufficient staff .... Need more staff members.")
        else
        {
          current.hours = current.hours - 1;
          current = this.head;
        }
    }
  }
}
/*LinkedList.prototype.timeTableGen= function ()
{
  document.write("Im pissed!");
  for(var i=0;i<=5;i++)
  {
    var current = this.head;
    document.write(current.hours);
    for(var j=0;j<=5;j++)
    {
      var l = list.lengthOfList();
      var r = Math.floor(Math.random()*(l-1));
      var k = 0;
      while(k!=r && current.next!=null)
      {
        current = current.next;
        document.write(current.data_name);
        k++;
      }
      if(current.hours == 0)
      {
        list.deleteWithName(current.data_name);
        current = self.head;
      }
      if(l==0)
        alert("Insufficient staff .... Need more staff members.")
      else
      {
      //fh.WriteLine(current.subject+'/'+ current.data_name + ',');
      current.hours = current.hours - 1;
      current = this.head;
      }
    }
  }
  */
list.Generate();

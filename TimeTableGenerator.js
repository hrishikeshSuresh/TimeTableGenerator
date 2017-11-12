$.ajax({ url: 'teachers_data.csv', dataType: 'text', }).done(timeTableGenerator);
function timeTableGenerator(data)
{
  var allRows = data.split(/\r?\n|\r/);
  for (var singleRow = 0; singleRow < allRows.length; singleRow++)
  {
    var rowCells = allRows[singleRow].split(',');
    list.push(rowCells[0],rowCells[1],rowCells[2]);
  }
  for(var i=0;i<=5;i++)
  {
    list.printName();
    var current = this.head;
    document.write(current.data_name);
    for(var j=0;j<=5;j++)
    {
      var l = list.lengthOfList();
      var r = Math.floor(Math.random()*l);
      var k = 0;
      while(k!=r && current.next!=null)
      {
        current = current.next;
        document.write(current.data_name);
        k++;
      }
      document.write('skip works');
      if(current.hours == 0)
      {
        list.deleteWithName(current.data_name);
        current = this.head;
      }
      if(l==0)
        alert("Insufficient staff .... Need more staff members.")
      else
      {
      //  fh.WriteLine(current.subject+'/'+ current.data_name + ',');
        current.hours = current.hours - 1;
        current = this.head;
      }
    }
  }
}

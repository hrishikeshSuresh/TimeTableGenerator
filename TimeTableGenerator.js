/*LinkedList.prototype.timeTableGen= function ()
{
  document.write("Im pissed!");
  var curr = this.head;
  document.write(curr.data_name);
  for(var i=0;i<=5;i++)
  {
    var current = self.head;
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
      current = self.head;
      }
    }
  }
}
list.readData();
list.printName();
list.timeTableGen();
*/

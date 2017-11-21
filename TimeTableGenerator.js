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
      list.push(rowCells[0]);
      list.print();
    }
  }
}

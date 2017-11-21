$.ajax({ url: 'final.csv', dataType: 'text', }).done(printingOnPage);
function printingOnPage(data)
{
   var allRows = data.split(/\r?\n|\r/);
   var table = '<table>';
   table +="<tr><th>TEACHER NAME</th><th>SUBJECT</th><br></tr>";
   for (var singleRow = 0; singleRow < allRows.length; singleRow++)
   {
     if (singleRow === 0 )
     {
       table += '<thead>';
       table += '<tr>';
     }
     else
     {
       table += '<tr>';
     }
     var rowCells = allRows[singleRow].split(',');
     for (var rowCellCount = 0; rowCellCount < rowCells.length; rowCellCount++)
     {
       if (singleRow === 0 || singleRow === 6 || singleRow ===12 || singleRow ===18 || singleRow === 24 )
       {
         table += '<th>';
         table += rowCells[rowCellCount];
         table += '</th></b>';
       }
       else
       {
         table += '<td>';
         table += rowCells[rowCellCount];
         table += '</td>';
       }
     }
     if (singleRow === 0)
     {
       table += '</tr>';
       table += '</thead></b>';
       table += '<tbody>';
     }
     else
     {
       table += '</tr>';
     }
   }
   table += '</tbody>';
   table += '</table>';
   $('body').append(table);
}

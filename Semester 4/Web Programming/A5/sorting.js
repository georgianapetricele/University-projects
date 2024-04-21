
    let sortOrder = ['', '', '', ''];

$(document).ready(function(){
        $('#myTable thead th').click(function() {
            let columnIndex = $(this).index();
            if(sortOrder[columnIndex] === 'asc') {
                sortOrder[columnIndex] = 'desc';
            }
            else if(sortOrder[columnIndex] === 'desc') {
                sortOrder[columnIndex] = 'asc';
            }
            else if(sortOrder[columnIndex] === '') {
                sortOrder[columnIndex] = 'asc';
            }
            sortTable(columnIndex, sortOrder[columnIndex]);
        });
});

$(document).ready(function() {
        $("#myTable tfoot td").click(function () {
            let columnIndex = $(this).index();
            let nextColumnIndex = (columnIndex + 1) % 4;
            let rows = $('#myTable tbody tr').get();

            $.each(rows, function (index, row) {
                let cells = $(row).children('td');
                let temp = cells.eq(columnIndex).text();
                cells.eq(columnIndex).text(cells.eq(nextColumnIndex).text());
                cells.eq(nextColumnIndex).text(temp);
            });
        });
    });

    function isNumeric(value) {
        if(value.type === 'string')
            return false;
        else
            return !isNaN(parseFloat(value));
    }
    function sortTable(columnIndex, sortOrder) {
        let rows = $('#myTable tbody tr').get();
        console.log(rows);

        rows.sort(function(rowA, rowB) {
            let x = $(rowA).children('td').eq(columnIndex).text();
            let y = $(rowB).children('td').eq(columnIndex).text();
            if (isNumeric(x) && isNumeric(y)) {
                return sortOrder === "asc" ? Number(x) - Number(y) : Number(y) - Number(x);
            } else {
                return sortOrder === "asc" ? x.localeCompare(y) : y.localeCompare(x);
            }
        });

        $.each(rows, function(index, row) {
            $('#myTable tbody').append(row);
        });
    }



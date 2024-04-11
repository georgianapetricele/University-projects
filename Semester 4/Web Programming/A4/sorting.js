

let cPrev = -1;
function sortBy(col) {
    const rows = document.getElementById("sortable").rows.length;
    const columns = document.getElementById("sortable").rows[0].cells.length;

    let arrTable = [...Array(rows)];

    for (let ro=0; ro<rows; ro++) {
            arrTable[ro] = document.getElementById("sortable").rows[ro].cells[col].innerHTML; // put the column into an array for sorting
        }

    let th = arrTable.shift(); //take out the header row from the array
    //console.log(arrTable);
    if (col !== cPrev) {
        arrTable.sort(
            function (a, b) {
                console.log(a, b);
                if (!isNaN(parseFloat(a)) && !isNaN(parseFloat(b))) {
                    a = parseFloat(a);
                    b = parseFloat(b);
                }
                if (a === b) {
                    return 0;
                } else {
                    return (a < b) ? -1 : 1;
                }
            }
        );
    } else {
        arrTable.reverse();
    }

    cPrev = col;

    arrTable.unshift(th);

    for (let ro=0; ro<rows; ro++) { // put the sorted array back into the table
        document.getElementById("sortable").rows[ro].cells[col].innerHTML = arrTable[ro];
    }
}
let currentPage = 0;

const insertData = (newBody, data) => {
    if (currentPage === 0) {
        $('#previousButton').attr('disabled', true);
    }
    let result = JSON.parse(data);
    let numberOfPages = Math.ceil(result.length/4);
    for (let log of result) {
        let newRow = newBody.insertRow();
        if (result.indexOf(log) >= 4 * currentPage) {
            for (let index of ['id', 'type', 'severity', 'date', 'user', 'logtext']) {
                let newCol = newRow.insertCell();
                let newText = document.createTextNode(log[index]);
                newCol.appendChild(newText);
            }
            newBody.append(newRow);
        }
        if (result.indexOf(log) >= 4 * currentPage + 3) {
            break;
        }
    }
    if (numberOfPages === 0) {
        $('#nextButton').attr('disabled', true);
    } else {
        if (currentPage === numberOfPages - 1) {
            $('#nextButton').attr('disabled', true);
        } else {
            $('#nextButton').attr('disabled', false);
        }
    }
}

const showLogsByUser = () => {
    let body = $('.logTable tbody').eq(0);
    let newBody = document.createElement('tbody');
    $.ajax({
        type: 'GET',
        url: "http://localhost/a6/database_utils.php",
        data: {action: 'selectLogsByUser'},
        success: (data) => {
            insertData(newBody, data);
            body.replaceWith(newBody);
            attachRowClickEvent();
        }
    })
   
}

const attachRowClickEvent = () => {
    $('tr').each(function() {
        $(this).click(function() {
            let rowData = $(this).children('td').map(function() {
                return $(this).text();
            }).get();
            // Populate the input boxes
            $('#idField').val(rowData[0]);
            $('#typeField').val(rowData[1]); // Fixed
            $('#severityField').val(rowData[2]); // Fixed
            $('#dateField').val(rowData[3]); // Fixed
            $('#userField').val(rowData[4]); // Fixed
            $('#logField').val(rowData[5]); // Fixed

            // showLogDetails(rowData);
        });
    });
}

const showLogDetails = (rowData) => {
    // Example: Show an alert with details of the clicked log
    let details = `Log ID: ${rowData[0]}\nType: ${rowData[1]}\nSeverity: ${rowData[2]}\nDate: ${rowData[3]}\nUser: ${rowData[4]}\nLog Text: ${rowData[5]}`;
    alert(details);
}

$(document).ready(() => {
    showLogsByUser();

    $('#removeLogButton').click(() => {
        if ($('#idField').val().trim().length > 0) {
            let id = Number($('#idField').val());
            if(confirm('Are you sure you want to delete the log with id ' + id + '?')) {
                $.ajax({
                    type: 'GET',
                    url: "http://localhost/a6/database_utils.php",
                    data: {
                        action: 'removeLog',
                        id: id
                    },
                    success: (data) => {
                        let res = JSON.parse(data);
                        if (res === 0) {
                            alert("You don't have the permission to delete the log/the log does not exist!");
                        } else {
                            currentPage = 0;
                            $('.form-control').val("");
                            showLogsByUser();
                        }
                    }
                })
            }
        } else {
            alert("Please select a log to remove!");
        }
    })

    $('#previousButton').click(() => {
        if (currentPage > 0) {
            currentPage--;
            if (currentPage === 0) {
                $('#previousButton').attr('disabled', true);
            }
        }
        showLogsByUser();
    })

    $('#nextButton').click(() => {
        $('#previousButton').attr('disabled', false);
        currentPage++;
        showLogsByUser();
    })
})
<?php
    $conn = new mysqli('localhost', 'phpmyadmin', 'gajen', 'RealtorSuit');
    $data = array();
    $table = $_GET['table'];
    $sql = "SELECT * FROM ".$table;
    $query = $conn->query($sql);
    while($row = $query->fetch_assoc()){
        $data[] = $row;
    }
    echo json_encode($data);
?>
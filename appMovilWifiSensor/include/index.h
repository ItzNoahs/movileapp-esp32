
#ifndef WEBPAGE_H
#define WEBPAGE_H

const char *webpage = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Sensor</title>
</head>
<body>
    <h1>ESP32 Sensor Infrarrojo</h1>
    <p>Infrarrojo: <span style="color: red;"><span id="infrared">Loading...</span> </span></p>
    <script>
        function fetchSensor() {
            fetch("/infrared")
                .then(response => response.text())
                .then(data => {
                    document.getElementById("infrared").textContent = data;
                });
        }

        fetchSensor();
        setInterval(fetchSensor, 50); // Update temperature every 4 seconds
    </script>
</body>
</html>
)=====";

#endif

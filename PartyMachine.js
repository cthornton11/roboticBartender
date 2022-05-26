
var firebase = require('firebase/app');
const { getDatabase, ref, onValue, set, get, update } = require('firebase/database');

// Your web app's Firebase configuration
const firebaseConfig = {
};

firebase.initializeApp(firebaseConfig);

const database = getDatabase();
var util = require('util')
set(ref(database, 'Drink/'), 10);
const { SerialPort } = require("serialport");
const serialPort = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 });

serialPort.on("open", function () {
    console.log('comm open');
    serialPort.on('data', function (data) {
        console.log('data received: ' + data);
    });
});

function sendCommand(drink) {
    serialPort.write(drink + '\n'), function (err) {
        if (err) {
            return console.log('error on write', err.message)
        }
        console.log('error message written')
    };
    console.log('sent to arduino');
}

// refrences the updat_light value from the database
const rumlemonadesprite = ref(database, "drink20/");
const bacardi = ref(database, "drink12/");
const bluecoke = ref(database, "drink3/");
const bluelemonade = ref(database, "drink1/");
const bluelemonadecoke = ref(database, "drink17/");
const bluelemonadesprite = ref(database, "drink16/");
const bluesprite = ref(database, "drink2/");
const coke = ref(database, "drink13/");
const lemonade = ref(database, "drink15/");
const pinkW = ref(database, "drink11/");
const pinkcoke = ref(database, "drink6/");
const pinklemonade = ref(database, "drink4/");
const pinklemonadecoke = ref(database, "drink19/");
const pinklemonadesprite = ref(database, "drink18/");
const pinksprite = ref(database, "drink5/");
const rumCoke = ref(database, "drink9/");
const rumSprite = ref(database, "drink8/");
const rumlemonade = ref(database, "drink7/");
const rumlemonadecoke = ref(database, "drink21/");
const sprite = ref(database, "drink14/");
const uvBlue = ref(database, "drink10/");

// refrences the whole database
var rootR = ref(database);

// checks if the update_light valueis true and if so creates a snapshot and calls getData
var startup = 0;

//checks if the update_light valueis true and if so creates a snapshot and calls getData
onValue(uvBlue, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 0) {
        sendCommand('uvBlue');
    }
    startup++;
});
onValue(pinkW, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 1) {
        sendCommand('pinkW');
    }
    startup++;
});
onValue(bacardi, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 2) {
        sendCommand('bacardi');
    }
    startup++;
});
onValue(coke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 3) {
        sendCommand('coke');
    }
    startup++;
});
onValue(sprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 4) {
        sendCommand('sprite');
    }
    startup++;
});
onValue(lemonade, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 5) {
        sendCommand('lemonade');
    }
    startup++;
});

onValue(bluelemonade, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 6) {
        sendCommand('blue lemonade');
    }
    startup++;
});
onValue(bluesprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 7) {
        sendCommand('blue sprite');
    }
    startup++;
});
onValue(bluecoke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 8) {
        sendCommand('blue coke');
    }
    startup++;
});
onValue(pinklemonade, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 9) {
        sendCommand('pink lemonade');
    }
    startup++;
});
onValue(pinksprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 10) {
        sendCommand('pink sprite');
    }
    startup++;
});
onValue(pinkcoke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 11) {
        sendCommand('pink coke');
    }
    startup++;
});
onValue(rumlemonade, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 12) {
        sendCommand('rum lemonade');
    }
    startup++;
});
onValue(rumSprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 13) {
        sendCommand('rum sprite');
    }
    startup++;
});
onValue(rumCoke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 14) {
        sendCommand('rum coke');
    }
    startup++;
});

onValue(bluelemonadesprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 15) {
        sendCommand('bluelemonadesprite');
    }
    startup++;
});
onValue(bluelemonadecoke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 16) {
        sendCommand('bluelemonadecoke');
    }
    startup++;
});
onValue(pinklemonadesprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 17) {
        sendCommand('pinklemonadesprite');
    }
    startup++;
});
onValue(pinklemonadecoke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 18) {
        sendCommand('pinklemonadecoke');
    }
    startup++;
});
onValue(rumlemonadesprite, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 19) {
        sendCommand('rumlemonadesprite');
    }
    startup++;
});
onValue(rumlemonadecoke, (snapshot) => {
    const data1 = snapshot.val();
    if (startup > 20) {
        sendCommand('rumlemonadecoke');
    }
    startup++;
});



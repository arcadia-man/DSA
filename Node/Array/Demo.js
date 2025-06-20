
const fs = require('fs');
const path = require('path');

async function test() {
  const ab = await fetch('https://www.google.com');
  const text = await ab.text(); // Parse HTML response
  console.log(text); // Logs the raw HTML content
  const cd = await fetch('https://api.sampleapis.com/baseball/hitsSingleSeason');
  const jsons = await cd.json();
  console.log(jsons);
}

const ex = {
  "id": 1,
  "name": "Electronics",
  "children": [
    { "id": 2, "name": "Mobiles", "children": [] },
    {
      "id": 3, "name": "Laptops", "children": [
        {
          "id": 4, "name": "Gaming Laptops", "children": [
          ]
        }
      ]
    }
  ]
}

function printNameRecursive(ex) {
  if (ex?.length > 0) {
    for (let i = 0; i < ex.length; i++) {
      console.log(ex[i].name)
      printNameRecursive(ex[i].children)
    }
  }
}

// test();
// printNameRecursive([ex])

function readAllDir(pwd) {
  let items = fs.readdirSync(pwd);
  for (let item of items) {
    const fullPath = path.join(pwd, item);
    console.log(fullPath)
  }
}
readAllDir('/home/pritamkumar/DSA')
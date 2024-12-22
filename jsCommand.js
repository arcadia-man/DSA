const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function askQuestion(query) {
  return new Promise((resolve) => {
    rl.question(query, (answer) => {
      resolve(answer);
    });
  });
}

async function performTask() {
  const inputs = [];
  for (let i = 1; i <= 10; i++) {
    const input = await askQuestion(`Enter input ${i}: `);
    inputs.push(input);
  }
  console.log(inputs);
  rl.close();
}

performTask();

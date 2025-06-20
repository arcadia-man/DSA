class RateLimiter {
  constructor(limit, intervalTime) {
    this.limit = limit;
    this.intervalTime = intervalTime;
    this.queue = []

    setInterval(() => {
      this.processQueue()
    }, intervalTime)
  }

  processQueue() {
    for(let i = 0; i < this.limit &&  this.queue.length > 0; i++){
      const fn = this.queue.shift();
      fn();
    }
  }

  schedule(request) {
    this.queue.push(() => this.handleRequest(request))
  }

  handleRequest(request) {
    throw new Error("This function should be overrided by child");
  }
}
module.exports = { RateLimiter };
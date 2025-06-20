const { RateLimiter } = require('./RateLimiter');

class SearchApiLimiter extends RateLimiter {
  static instance;

  constructor() {
    super(5, 5000)
  }

  static getInstance() {
    if (this.instance) {
      return this.instance;
    } else {
      this.instance = new SearchApiLimiter();
      return this.instance;
    }
  }

  handleRequest(request) {
    console.log(request)
  }
}

module.exports = { SearchApiLimiter };
const { SearchApiLimiter } = require("./SearchLimiter");


for (let i = 0; i < 100; i++) {
  const searchLimiter = SearchApiLimiter.getInstance()
  searchLimiter.schedule({ query: 'chatgpt', key: i });
}
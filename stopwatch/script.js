// set constant values
const milisec = document.querySelector('.milliseconds')
const sec = document.querySelector('.seconds')
const min = document.querySelector('.minutes')
const hour = document.querySelector('.hours')
const button = document.querySelector('.start')

// create variables that can be updated
let miliNum = 0
let secNum = 0
let minNum = 0
let hourNum = 0
let INTERVAL

// update values
function milliseconds() {
  miliNum++
  // adding zero if less than 10
  if (miliNum < 10) {
    milisec.innerHTML = '0' + miliNum
  }
  else {
    milisec.innerHTML = miliNum
  }
  // incrementing after 99
  if (miliNum == 99) {
    miliNum = 0
    seconds()
  }
}
function seconds() {
  secNum++
  if (secNum < 10) {
    sec.innerHTML = '0' + secNum
  }
  else {
    sec.innerHTML = secNum
  }
  // incrementing after 60
  if (secNum == 59) {
    secNum = 0
    minutes()
  }
}
function minutes() {
  minNum++
  if (minNum < 10) {
    min.innerHTML = '0' + minNum
  }
  else {
    min.innerHTML = minNum
  }
  // after 59 minutes, call hours
  if (minNum == 59) {
    minNum = 0
    hours()
  }
}

function hours() {
  hourNum++
  if (hourNum < 10) {
    hour.innerHTML = '0' + hourNum
  }
  else {
    hour.innerHTML = hourNum
  }
}

// call functions when start is pressed
function start() {
  clearInterval(INTERVAL)
  INTERVAL = setInterval(() => {
    milliseconds()
  }, 10)
}

// stops increasing
function stop() {
  clearInterval(INTERVAL)
  button.innerHTML = "RESUME"
}

// stop and clear board
function reset () {
  clearInterval(INTERVAL)
  miliNum = 0
  secNum = 0
  minNum = 0
  milisec.innerHTML = '00'
  sec.innerHTML = '00'
  min.innerHTML = '00'
  button.innerHTML = "START"
}